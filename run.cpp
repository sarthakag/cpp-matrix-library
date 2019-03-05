#include <bits/stdc++.h>
#include "matrix.hpp"
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define mkp make_pair
#define nl cout<<endl
#define MOD 1000000007
#define loop(i,start,end) for(ull i=start;i<end;i++)
#define N 100001
#define oa(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define ov(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";nl
int main() 
{
    fastio();
    #ifndef ONLINE_JUDGE
    	freopen("in.txt","r",stdin);
    	freopen("out.txt","w",stdout);
    #endif

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

  