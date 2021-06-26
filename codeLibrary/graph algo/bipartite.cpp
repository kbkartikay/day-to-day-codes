#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
#define PI   3.141592653593
const long long mod = 1e9 + 7ll ;
#define EPS  0.000000001
#define INF  0X3f3f3f3f
 
//bipartite check, if bipartite do 2 coloring, simple shit
#define N 100007
int color[N];
vector<int>adj[N];
bool check=false;
int vis[N];
void dfs(int v,int clr)
{
    color[v]=clr;
    vis[v]=1;
    for(auto x : adj[v])
    {
        if(!vis[x])dfs(x,clr^1);
        else
        {
            if(color[x]!=clr^1)check=true;
        }
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
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
  if(check)cout<<"IMPOSSIBLE\n";
  else
  {
      for(int i=1;i<=n;i++)cout<<color[i]+1<<" ";
  } 
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
