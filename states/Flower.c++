//https://codeforces.com/contest/474/problem/D
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
   
   
   
   int t,k;
   cin>>t>>k;
   lli dp[(int)1e5+1][2];
   forr(i,1,k+1) dp[i][1]=1;
   dp[k][0]=1;
   lli sum=0;
   for(int i=k+1;i<1e5+1;i++)
   {
	   //white case  (if current flower to eat is white)
	   dp[i][0]=sum+dp[i-k][1]+dp[i-k][0];			//previous k whites
	   if(dp[i][0]>=MOD) dp[i][0]=dp[i][0]%MOD;
	   //black case	 (if current flower to eat is black)
	   dp[i][1]=dp[i-1][0]+dp[i-1][1];			
	   if(dp[i][1]>=MOD) dp[i][1]=dp[i][1]%MOD;
   }
   
   vector<lli> pref((int)1e5+1,0);
   forr(i,1,(int)1e5+1)
   {
	   pref[i]=dp[i][1]+dp[i][0]+pref[i-1];
	   if(pref[i]>MOD) pref[i]=pref[i]%MOD;
   }
   
   while(t--)
   {
	   int a,b;
	   cin>>a>>b;
	   lli ans=pref[b]-pref[a-1];
	   if(ans<0) ans+=MOD;
	   cout<<ans%MOD<<"\n";
   }
   
   
   	
    
    
    

    return 0;
}



















