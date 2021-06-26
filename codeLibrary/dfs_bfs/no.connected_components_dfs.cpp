
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n) for (ll i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
ll n;
ll edge;
void dfs(vvi &adj,int s,vector<bool> &visited)
{
    visited[s]=true;
    for(auto j : adj[s])
    {
        if(!visited[j])
            dfs(adj,j,visited);

    }


}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

ll t;
cin>>t;
while(t--)
{

    cin>>n;
    cin>>edge;
    vvi adj(n);
    ll s=0;
    vector<bool> visited(n,false);
    for(ll i=0;i<edge;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        if(!visited[i])
        {dfs(adj,i,visited);
        cnt++;
        }
    }
    cout<<cnt<<endl;
}


}
