/*
#######################################################
# Its all going to be daijobu  #
#######################################################
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
//#define int long long
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
//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=5007;
vi adj[MAXN];
int vis[MAXN];
vpi ans(MAXN);
void dfs(int v,int p=-1)
{
    if(p!=-1)
    {
        ans.PB({p,v});
    }
    vis[v]=1;
    for(auto x : adj[v])
    {
        if(!vis[x])dfs(x,v);
    }
}
void solve()
{
    
    int n;
    cin>>n;
    //clear stuff
    ans.clear();
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)adj[i].clear();
    //
    vi a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]!=a[j])
            {
                adj[i].PB(j);adj[j].PB(i);
            }
        }
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for(auto x : ans)
    {
        cout<<x.F<<" "<<x.S<<endl;
        
    }

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
   
