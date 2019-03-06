/*
	Boost Competency Test
	Author: Sarthak Agarwal
	Institute: BITS Pilani
*/
#ifndef MATRIX_HPP
#define MATRIX_HPP
#include<bits/stdc++.h>
using namespace std;

template<class T> 
class matrix{ 
public: 
	using value_type = T;
	vector<vector<T> >mat;
	size_t row_size, col_size;
	// Constructors
	matrix ();
	matrix (const size_t row_size, const size_t col_size);
	// matrix (const matrix &M); 

	T get(const size_t row_num,const size_t col_num);
	T set(const size_t row_num,const size_t col_num, T val);
	const T& operator()(size_t x, size_t y) const { return mat[x][y]; }
	T& operator()(size_t x, size_t y) { return mat[x][y]; }

	pair<size_t,size_t> size();
	size_t rsize();
	size_t csize();

	template <typename E>
	matrix<T>& operator=(const E& expression) {
		for (size_t i = 0; i != row_size; i++) {
			for (size_t j = 0; j != col_size; j++) {
				mat[i][j] = expression(i, j);
			}
		}
		return *this;
	}
	template <typename E>
	matrix<T>& operator+=(const E& expression) {
		for (size_t i = 0; i != row_size; i++) {
			for (size_t j = 0; j != col_size; j++) {
				mat[i][j] = mat[i][j] + expression(i, j);
			}
		}
		return *this;
	}
	template <typename E>
	matrix<T>& operator-=(const E& expression) {
		for (size_t i = 0; i != row_size; i++) {
			for (size_t j = 0; j != col_size; j++) {
				mat[i][j] -= expression(i, j);
			}
		}
		return *this;
	}

	void show();

}; 

// Matrix Addition using Expression Templates
template <typename LHS, typename RHS>
class matrixSum
{
public:
	using value_type = typename LHS::value_type;

	matrixSum(const LHS& lhs, const RHS& rhs) : rhs(rhs), lhs(lhs) {}
	
	value_type operator() (int x, int y) const  {
		return lhs(x, y) + rhs(x, y);
	}
private:
	const LHS& lhs;
	const RHS& rhs;
};
template <typename LHS, typename RHS>
matrixSum<LHS, RHS> operator+(const LHS& lhs, const RHS& rhs) {
	return matrixSum<LHS, RHS>(lhs, rhs);
}

// Matrix Substraction using Expression Templates
template <typename LHS, typename RHS>
class matrixSub
{
public:
	using value_type = typename LHS::value_type;

	matrixSub(const LHS& lhs, const RHS& rhs) : rhs(rhs), lhs(lhs) {}
	
	value_type operator() (int x, int y) const  {
		return lhs(x, y) - rhs(x, y);
	}
private:
	const LHS& lhs;
	const RHS& rhs;
};
template <typename LHS, typename RHS>
matrixSub<LHS, RHS> operator-(const LHS& lhs, const RHS& rhs) {
	return matrixSub<LHS, RHS>(lhs, rhs);
}

// Matrix Multiplication
template <class T>
matrix<T>operator*(const matrix<T> &M1, const matrix<T> &M2) {
	if( M1.col_size != M2.row_size ){
		return M1;
	}
	matrix<T> result(M1.row_size, M2.col_size);
	for (size_t i = 0; i < M1.row_size; i++) {
		for (size_t j = 0; j < M2.col_size; j++) {
			result.set(i,j,0);
			for (size_t k = 0; k < M1.col_size; k++)
				result.mat[i][j] += M1.mat[i][k] * M2.mat[k][j];
		}
	}
	return result;
}

// Scaler Multiplication
template <class T>
matrix<T> operator * (const T& val, matrix <T>& M) {
	size_t row = M.rsize();
	size_t col = M.csize();
	matrix <T> result(row, col); 
	for(size_t i = 0; i < row; ++i) {
		for(size_t j = 0; j < col; ++j) {
			result.set(i, j, val * M.get(i, j));
		}
	}
	return result; 
}


template <class T>
matrix<T>::matrix()
{
	row_size = 0;
	col_size = 0;
}
template <class T>
matrix<T>::matrix (const size_t row_sz, const size_t col_sz)
{
	row_size = row_sz;
	col_size = col_sz;
	mat.resize(row_size);
	for(size_t i = 0; i < row_size ; i++)
	{
		mat[i].resize(col_sz,0);
	}
}

template <class T>
T matrix<T>:: get(const size_t row_num,const size_t col_num)
{
	return mat[row_num][col_num];
}

template <class T>
T matrix<T>:: set(const size_t row_num,const size_t col_num, T val)
{
	return mat[row_num][col_num] = val;
}

template<class T>
pair<size_t,size_t> matrix<T>::size()
{
	return make_pair(row_size,col_size);
}

template <class T>
size_t matrix<T>:: rsize()
{
	return row_size;
}

template <class T>
size_t matrix<T>:: csize()
{
	return col_size;
}

// Prints all values in matrix
template <class T> 
void show(matrix<T> &M) {
	for(size_t i = 0; i < M.row_size ; i++) {
		for(size_t j = 0; j < M.col_size ; j++)
			cout << M.get(i,j) << " ";
		cout << endl;
	}
}

#endif