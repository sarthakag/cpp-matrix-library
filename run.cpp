#include <bits/stdc++.h>
#include "matrix.hpp"
using namespace std;
int main() 
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    matrix<int>m1(3,3),m2(3,3),m3(3,3),m4(3,4),m5(3,4);
    for(int i=0;i<3;i++)
    {
    	for(int j = 0;j<3;j++)
    		m1.set(i,j,i),m2.set(j,i,j);
    }

	show(m1);nl;
	show(m2);nl;

	m3 = m1*m2;
	m1=m2;

	show(m3);nl;
	show(m1);



	return 0;
}

  