//https://codeforces.com/problemset/problem/118/D
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
   
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	
	
	int tot=n1+n2;
	//int dp[current position][number of footmen used uptill current position][consecutive footmen][consecutive horsemen]
	
	//note number of horsemen used=current position - no. of footmen used
	
	int  dp[tot+1][n1+1][2][max(k1,k2)+1];
	memset(dp,0,sizeof(dp));
	dp[1][1][0][1]=1;
	dp[1][0][1][1]=1;
	forr(i,1,tot+1)
	{
		for(int h=0;h<=n1;h++)
		{
			//insert footmen after horse men
			if(i-h<=n2)
			{
				
				for(int l1=1;l1<=k1 && h>=l1;l1++)
				{
					if(h)
					{
						dp[i][h][1][1]+=dp[i-1][h][0][l1];
						dp[i][h][1][1]=dp[i][h][1][1]%MOD;
					}
				}
				//insert footmen after footmen
				for(int l2=2;l2<=k2;l2++)
				{
					dp[i][h][1][l2]+=dp[i-1][h][1][l2-1];
					dp[i][h][1][l2]=dp[i][h][1][l2]%MOD;
				}
				
				//insert horsemen after footmen
				for(int l2=1;l2<=k2;l2++)
				{
					if(h) {
						dp[i][h][0][1]+=dp[i-1][h-1][1][l2];
						dp[i][h][0][1]=dp[i][h][0][1]%MOD;
					}
				}
				//insert horesemen after horsemen
				for(int l1=2;l1<=k1;l1++)
				{
					if(h) {
						dp[i][h][0][l1]=dp[i-1][h-1][0][l1-1];
						dp[i][h][0][l1]=dp[i][h][0][l1]%MOD;
					}
				}
			}
			
		}
		
	}
	
	int  sum=0;
	forr(i,1,k1+1)	{sum+=dp[tot][n1][0][i];if(sum>=MOD) sum=sum%MOD;}
	forr(i,1,k2+1)  {sum+=dp[tot][n1][1][i];if(sum>=MOD) sum=sum%MOD;}
	cout<<sum<<"\n";
    

    return 0;
}




















 
