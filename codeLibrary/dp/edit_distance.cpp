#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//Constants
#define PI   3.141592653593
const long long mod = 1e9 + 7ll ;
#define EPS  0.000000001
#define INF  0X3f3f3f3f

 
int dp[5007][5007];
 
void solve()
{
   string s1,s2;
   cin>>s1>>s2;
   for(int i=0;i<=s1.size();i++)
   {
       for(int j=0;j<=s2.size();j++)
       {
           if(i==0)dp[i][j]=j;
           else if(j==0) dp[i][j]=i;
           else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
           else
           {
               dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
           }
       }
 
   }
   int m=(int)s1.size();
   int n=(int)s2.size();
cout<<dp[m][n];
}
 
int32_t main()
{
IOS;
TIE;     
#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
#endif
solve();   
}
