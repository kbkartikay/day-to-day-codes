/*
#######################################################
# Datebayo!  #
#######################################################
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
#define int long long
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
vi intime(MAXN);
vi outtime(MAXN);
int timer;
vi adj[MAXN];
int n;
int table[32][MAXN];
vi depth(MAXN);
vi parent(MAXN);
void dfs(int u,int d,int p=0)
{
    parent[u]=p;
    intime[u]=++timer;
    depth[u]=d;
    for(auto x : adj[u])
    {
        if(x!=p)
        {
            dfs(x,d+1,u);
        }
    }
    outtime[u]=++timer;
}
 
 
 
void build_table()
{
    for(int j=1;j<=n;j++) table[0][j]=parent[j];
    for(int i=1;1<<i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        table[i][j]=table[i-1][table[i-1][j]];
    }
}
void preprocess()
{
    timer=0;
    for(int i=1;i<=n;i++)
    {
        intime[i]=0;
        outtime[i]=0;
        adj[i].clear();
        depth[i]=0;
    }
    //memset(table,0,sizeof(table));
}
bool isancestor(int u,int v)
{
    if(intime[u]<=intime[v] && outtime[u]>=outtime[v]) return true;
    return false;
}
int lca1(int x,int y)//logn
{
   if(isancestor(x,y))return x;
   if(isancestor(y,x))return y;
   int l=ceil(log2(n));
   for(int i=l;i>=0;i--)
   {
       int node=table[i][x];
       if(node==0) continue;
       if(!isancestor(node,y)) x=node;
   } 
   x=table[0][x];
   return x;
}
int walk(int node,int dist)
{
    for(int i =0 ;1<<i<=dist;i++)
    {
        if((1<<i)&dist)
        {
            node=table[i][node];
        }
    }
    return node;
}
bool isOK(int x,int y,int mid)
{
    if(walk(x,mid)==walk(y,mid)) return true;
    return false;
}
int lca2(int x,int y)
{
    if(depth[x]<depth[y])
     swap(x,y);
    if(depth[x]!=depth[y])
    x=walk(x,depth[x]-depth[y]);
    if(x==y) return x;
    int l=1;int r=n;
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
    preprocess();
    
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].PB(i); adj[i].PB(x);
    }
    dfs(1,0);
    build_table();
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<lca1(x,y)<<endl;
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
 
solve();
 
}
  
