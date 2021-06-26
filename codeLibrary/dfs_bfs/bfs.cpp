#include<bits/stdc++.h>
using namespace std;
//some stupid mistake in bfs
typedef int ll;
typedef unsigned long long ull;

#define rep(i,n) for (ll i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
void show_list(vector<vector<int>> &v,int n)
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"adj list over\n";
}
int bfs(vector<vector<int>> &adj,int s,int nodes)

{
queue<ll> q;
q.push(s);
vector<int> level(nodes,-1);
level[s]=0;
while(!q.empty())
{
    int k=q.front();
    q.pop();
    for(auto i: adj[k])
    {
        if(level[i!=-1]) continue;
        level[i]=level[k]+1;
        q.push(i);
    }
}
for(auto i:level)
{
    cout<<i<<" ";
}


    return level[nodes-1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
ll t;
cin>>t;
while(t--)
{

   ll nodes,edges;
   cin>>nodes>>edges;
   vvi adj(nodes);
   for(ll i=0;i<edges;i++)
   {
       ll x,y;
       cin>>x>>y;
       adj[x].push_back(y);
   }
   show_list(adj,nodes);
  int ans= bfs(adj,0,nodes);
  //cout<<ans<<endl;
}


}
