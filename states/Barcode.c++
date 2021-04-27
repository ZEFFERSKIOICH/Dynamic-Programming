//https://codeforces.com/problemset/problem/225/C
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
    
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	y=min(m,y);
	char ch[n+1][m+1];
	forr(i,1,n+1)
	{
		string s;
		cin>>s;
		forr(j,0,s.size())
		{
			ch[i][j+1]=s[j];
		}
	}
	vector<lli> pw(m+1,0),pb(m+1,0);


	// pw is prefix sums for whites
	// pb is prefix sums for balck

	for(int i=1;i<=m;i++)
	{
		int c=0;
		for(int j=1;j<=n;j++)
		{
			if(ch[j][i]=='#') c++;
		}
		pw[i]=pw[i-1]+c;
		pb[i]=pb[i-1]+n-c;
	}



	vector<vector<lli>> dp(m+1,vector<lli> (2,INF));
	//dp[column][color] gives min changes till column i for color j


	//initialising dp states
	forr(i,1,y+1)
	{
		dp[i][0]=pb[i]; 
		dp[i][1]=pw[i];
	}
	dp[0][0]=0;
	dp[0][1]=0;

	for(int i=x+1;i<=m;i++)
	{
		for(int j=max(x+1,i-y+1);j<=i-x+1;j++)
		{
			dp[i][0]=min(dp[i][0],dp[j-1][1]+pb[i]-pb[j-1]); //black before white
			dp[i][1]=min(dp[i][1],dp[j-1][0]+pw[i]-pw[j-1]); //white before black

		}
	}
	cout<<min(dp[m][0],dp[m][1])<<"\n";//minimum of sequence ending with color black,white
		
	
	
    
    
    

    return 0;
}




















