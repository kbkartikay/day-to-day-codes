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
//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=2e5+7;
vi adj[MAXN];
int flag;
int vis[MAXN];
void dfs(int v)
{
    vis[v]=1;
    if(adj[v].size()!=2)flag=1;
    for(auto x:adj[v])
    {
        if(!vis[x])dfs(x);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].PB(y);adj[y].PB(x);

    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            flag=0;
            dfs(i);
            if(flag==0)ans++;
        }
    }
    cout<<ans<<endl;
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

solve();

}
   
