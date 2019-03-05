#include <bits/stdc++.h>
#include "matrix.hpp"
using namespace std;
matrix<int>m1(3, 3), m2(3, 3), m3(3, 3), m4(3, 3);
clock_t startTime = clock(), endTime = clock();
/*
	Function to print all
	matrices
*/
void showall()
{
	show(m1);
	cout << endl;
	show(m2);
	cout << endl;
	show(m3);
	cout << endl;
	show(m4);
	cout << endl;

}
/*
	Prints time after each operator
*/
void ShowSetTime(string s)
{
	endTime = clock(); 
	cerr<<"Time taken by " <<s<<" operator = " << double(endTime - startTime) / CLOCKS_PER_SEC <<endl;
	startTime = clock();
}

int main() 
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);


	// Initialisation
	for (int i = 0; i < 3; i++){
		for (int j = 0;j<3;j++){
			m1.set(i,j,i+3-j);
			m2.set(j,i,j+1+i);
			m3.set(i,j,2);
		}
	}


	startTime = clock();
	m4 = m1 + m2 + m3;
	// showall(); 
	ShowSetTime("+");

	m4 = m1 - m2 - m3;
	// showall();
	ShowSetTime("-");

	m1 += m2;
	// showall();
	ShowSetTime("+=");

	m3 -= m2;
	// showall();
	ShowSetTime("-=");

	m4 = m1*m2;
	// showall();
	ShowSetTime("*");

	return 0;
}

  