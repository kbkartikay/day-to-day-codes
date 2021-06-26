
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
ll pos;
void bfs(vvi &adj,vi &level, ll s)
{
    level[s]=0;
    queue<ll>q;
    q.push(s);
    while(!q.empty())
    {
        ll y=q.front();
        q.pop();
        for(auto x: adj[y])
        {
            if(level[x]!=-1) continue;
            q.push(x);
            pos=x;
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
ll n;
cin>>n;
vvi adj(n+7);
vi level(n+7,-1);
for(ll i=0;i<n-1;i++)
{
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
bfs(adj,level,1);
memset(level,-1,sizeof(level));
bfs(adj,level,pos);
cout<<level[pos]<<endl;


}
