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
int a[5007];int b[5007];
int state(int n ,int m)
{
    if(dp[n][m]!=-1)return dp[n][m];
    if(n==m)return dp[n][m]=a[n]*b[m];
    if(n>m) return 0;
    
    dp[n][m]=state(n+1,m-1) + (a[n]*b[m]) +(a[m]*b[n]);
    
    return dp[n][m];

}
void solve()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int sum=0;
    
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int j=0;j<n;j++)state(0,j);
    for(int j=n-1;j>=0;j--)state(j,n-1);
    int ans=-INF;
    vector<int>cum(n);
    cum[0]=a[0]*b[0];
    for(int i=1;i<n;i++)
    {
        cum[i]= cum[i-1] + (a[i]*b[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i!=0)dp[i][j]=dp[i][j] + cum[i-1] + (cum[n-1]-cum[j]);
            else dp[i][j]=dp[i][j]  + (cum[n-1]-cum[j]);

        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
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