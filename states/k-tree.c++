//https://codeforces.com/contest/431/submission/113180729
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
const ulli MOD=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    
	int n,k,d;
	cin>>n>>k>>d;
	
	vector<vector<lli>> dp(2,vector<lli> (n+1,0));
	dp[0][0]=1;

	//dp[0][i] represents that edge d or above has not been added
	//dp[1][i] represents that edge d or above has been added

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(j>i) break;
			if(j<d)
			{
				//adding edges less than d 
				dp[0][i]+=dp[0][i-j];
				dp[1][i]+=dp[1][i-j];
				dp[1][i]=dp[1][i]%MOD;
				dp[0][i]=dp[0][i]%MOD;
			}
			else
			{
				//adding edges greater than d dp[0][i] converts to dp[1][i]
				dp[1][i]+=dp[0][i-j];
				dp[1][i]=dp[1][i]%MOD;
				dp[1][i]+=dp[1][i-j];
				dp[0][i]=dp[0][i]%MOD;
			}
		}
	}

	cout<<dp[1][n]%MOD<<"\n";

    return 0;
}




















