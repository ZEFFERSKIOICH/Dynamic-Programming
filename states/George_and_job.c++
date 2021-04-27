//https://codeforces.com/problemset/problem/467/C
// coded by zeffy
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zeroupper") //Enable AVX
#pragma GCC target("avx","popcnt")  //Enable AVX
#include <x86intrin.h> //SSE Extensions
#include <bits/stdc++.h> 
using namespace std;
#define eb emplace_back
#define mp make_pair
#define hello cout<<"hello"<<"\n"
#define forr(i,a,b) for(int i=a;i<b;i++)
#define it(s)	for(auto itr:s)
#define dvg(s) 	for(auto itr:s)	cout<<itr<<" ";cout<<endl;
#define dbg(s)	cout<<#s<<"= "<<s<<endl;
typedef long long int lli;
typedef unsigned long long int ulli;
const lli INF=(lli)1e17+5;
const ulli MOD=1e8;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
   
	//dp[s][i];
	
	lli n,m,k;
	cin>>n>>m>>k;
	vector<lli> v(n+1,0);
	forr(i,1,n+1) cin>>v[i];
	lli dp[k+1][n+1];
	memset(dp,0,sizeof(dp));
	// dp[i][j] represents number of segment and current position


	vector<lli> pref(n+1,0);
	forr(i,1,n+1)
	{
		pref[i]=v[i]+pref[i-1];
	}
	
	forr(i,1,m+1) dp[1][i]=pref[i];
	forr(i,1,k+1)
	{
		forr(j,m,n+1)
		{
			dp[i][j]=dp[i][j-1];  //case where current (i) is not included in any of the segment
			if(j>=m) dp[i][j]=max(dp[i][j],dp[i-1][j-m]+pref[j]-pref[j-m]);//case where current (i) is included in a segment
		}
	}	
	cout<<dp[k][n]<<"\n";
	
    return 0;
}









