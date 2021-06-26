/*
#######################################################
# Its all going to be daijobu  #
#######################################################
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
#define int long long
//typedef long long ll;
#define all(a) a.begin(),a.end()
//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f
//loops
#define REP(i,n)        for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)
//STL
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define PB push_back
#define vvi vector<vi>
#define vvll vector<vll>
#define F first
#define S second
//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//templates
//for usaco

//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=2007;
int dp[MAXN][2*MAXN];
void solve()
{
    int n;
    cin>>n;
    vi a(2*n);
    for(int i=0;i<2*n;i++)cin>>a[i];
    int cnt=0;
    a.PB(INT_MAX);
    vi ans;
    
    int num=a[0];
    for(int i=0;i<2*n;i++)
    {
        cnt++;
        if(a[i+1]>num)
        {
            ans.PB(cnt);
            cnt=0;
            num=a[i+1];
        }
    }
    int sz=(int)ans.size();
    //for(auto x : ans)cout<<x<<" ";
    //cout<<endl;
   
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sz;j++)//careful 0 based
        {
            if(i==0 && j==0)dp[i][j]=1;
            else if(j==0)dp[i][j]=0;
            else if(i==0)dp[i][j]=1;
            
            else
            {
                if(i>=ans[j-1])
                {
                    dp[i][j]=dp[i][j-1] || dp[i-ans[j-1]][j-1];
                }
                else dp[i][j]=dp[i][j-1];
            }
            
            
        }
    }
    if(dp[n][sz])cout<<"YES\n";
    else cout<<"NO\n";    



}

int32_t main(){
IOS;
TIE;     
#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
#endif   

int t;
cin>>t;
while(t--)solve();

}
   
