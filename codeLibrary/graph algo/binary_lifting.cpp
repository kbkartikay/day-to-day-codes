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
//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//templates
//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=200007;
vi adj[MAXN];
vi depth(MAXN);
vi parent(MAXN);
int table[32][MAXN];
int n;
void dfs(int u,int d,int p=0)
{
    parent[u]=p;
    depth[u]=d;
    for(auto x : adj[u])
    {
        if(x!=p)
        {
            dfs(x,d+1,u);
        }
    }
}
void build_table()
{
    for(int i=1;i<=n;i++) table[0][i]=parent[i];
    
    for(int i=1;1<<i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            table[i][j]=table[i-1][table[i-1][j]];
        }
    }
    //for(int i=0;i<=col;i++)
    //{
    //    for(int j=0;j<=n;j++)
    //    cout<<table[i][j]<<" ";
       // cout<<endl;
//
   // }
 
}
int walk(int node,int dist)
{
    //int len=floor(log2(dist));
    for(int i=0;1<<i<=dist;i++)
    {
        if(dist&(1<<i))
        {
            node=table[i][node];
        }
    }
    if(node==0) return -1;
    else
    return node;
}
bool isOK(int x,int y,int mid)
{
    if(walk(x,mid)==walk(y,mid)) return true;
    return false;
}
int lca(int x,int y)
{
    if(depth[x]<depth[y]) swap(x,y);
    int move=depth[x]-depth[y];
    x=walk(x,move);
    if(x==y) return x; // just a nice thing when direct child of y
    int l=0;int r=n;
    int ans;
    while(l<=r)
    {
        int mid=(r-l)/2 + l;
        if(isOK(x,y,mid))
        {
            ans=walk(x,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
return ans;
 
}
void solve()
{
    int q;
    cin>>n>>q;
    //reseting
    
    //
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].PB(i);adj[i].PB(x);
    }
    dfs(1,0);
    //for(int i =1;i<=n;i++)cout<<depth[i]<<" ";
    //cout<<endl;
    build_table();
    
    
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<walk(x,y)<<endl;
    }
    
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
 
solve();
 
 
}
