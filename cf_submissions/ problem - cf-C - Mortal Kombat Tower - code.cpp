/*
#######################################################
# Datebayo!  #
#######################################################
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
typedef long long ll;
#define all(a) a.begin(),a.end()
//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f
//loops
#define REP(i,n)        for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<=(b);++i)
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
//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//templates
//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=200007;
vi a(MAXN);
int dp[MAXN][2];
int n;
int play(int pos,int turn)
{
    if(pos>n) return 0;
    if(dp[pos][turn]!=-1) return dp[pos][turn];
    if(turn==0)
    {
        dp[pos][turn]= min(play(pos+1,1),play(pos+2,1));
        
    }
    if(turn==1)
    {
        dp[pos][turn] =  min((a[pos]+play(pos+1,0)),(a[pos]+a[pos+1]+play(pos+2,0)));
       
    }
     return dp[pos][turn];
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    //cout<<endl;
    cout<<play(1,1)<<endl;
}

int main(){
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
while(t--)
solve();


}
   
