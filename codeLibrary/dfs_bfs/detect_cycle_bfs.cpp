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
bool bfs(vvi &adj,vector<bool> &visited,ll s)
{
    visited[s]=true;
    queue<ll>q;
    q.push(s);

    while(!q.empty())
    {
        ll y=q.front();
        q.pop();
        ll cnt=0;
        for(auto x : adj[y])
        {

            if(visited[x])
            {
                cnt++;
                if(cnt>1) return true;
            }
            if(!visited[x])
            {
                visited[x]=true;
                q.push(x);
            }
        }
    }
    return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

ll n,e;
cin>>n>>e;
vvi adj(n+7);
for(ll i=0;i<e;i++)
{
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
ll flag=1;
vector<bool> visited(n+7,false);
if(bfs(adj,visited,1))
    {cout<<"NO"<<endl;
    flag=0;
    }
else {
 for(ll i=1;i<n+1;i++)
{
    if(!visited[i])
    {
       cout<<"NO"<<endl;
       flag=0;
       break;
    }
}
      }
 if (flag)
     cout<<"YES"<<endl;
}
