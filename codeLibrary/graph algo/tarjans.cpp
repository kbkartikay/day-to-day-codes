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
bool visited[111111];
#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
void t_sort(ll v,vector<ll> &order,vvi &adj1)
{
    visited[v]=true;
    for(auto x: adj1[v])
    {
        if(!visited[x])
        t_sort(x,order,adj1);
    }
    order.push_back(v);
}
void dfs(ll v,vector<ll> &component, vvi &adj2)
{
    visited[v]=true;
    component.push_back(v);
    for(auto x : adj2[v])
    {
        if(!visited[x])
        dfs(x,component,adj2);
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
ll n,e;
cin>>n>>e;
vvi adj1(n+7); vvi adj2(n+7);
for(ll i=1;i<=e;i++)
{
    ll x,y;
    cin>>x>>y;
    adj1[x].push_back(y);
    adj2[y].push_back(x);

}
vector<ll>order;
memset(visited,false,sizeof(visited));
for(ll i=1;i<=n;i++)
{
    if(!visited[i])
    t_sort(i,order,adj1);
}
for(ll i=n-1;i>=0;i--)
cout<<order[i]<<" ";
cout<<endl;
memset(visited,false,sizeof(visited));
vector<ll> component;
for(ll i=1;i<=n;i++)
{
    ll point=order[n-i];
    if(!visited[point])
    {dfs(point,component,adj2);
    for(ll j=0;j<component.size();j++)
    cout<<component[j]<<" ";
    cout<<endl;
    component.clear();
    }
}


}
