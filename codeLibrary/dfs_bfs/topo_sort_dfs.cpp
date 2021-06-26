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
ll n,e,s,t;
bool visited[111111];
void dfs(vi &v,vvi &adj,ll s)
{
    visited[s]=true;
    for(auto x: adj[s])
    {
        if(!visited[x])
        {

          dfs(v,adj,x);

        }
    }
    v.push_back(s);
}

void ans(vi &dp,vi &v,vvi &adj)
{
    for(ll i=0;i<v.size();i++)
    {
        for(auto x : adj[v[i]])
        {

            dp[v[i]]=(dp[v[i]]+dp[x])%MOD;

        }
    }
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    ll times;
    cin>>times;
    while(times--)
    {

        cin>>n>>e>>s>>t;
        vvi adj(n+7);
        for(ll i=0;i<e;i++)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
        }
        vector<ll>v;
        vector<ll>dp(n+7,0);
        dp[t]=1;
        memset(visited,false,sizeof(visited));
        for(ll i=1;i<n+1;i++)
        {
        if(!visited[i])
        dfs(v,adj,i);
        }
        //for(ll i=0;i<v.size();i++)
        //cout<<v[i]<<" ";
        //cout<<endl;
        ans(dp,v,adj);
        cout<<dp[s]<<endl;
    }



}

