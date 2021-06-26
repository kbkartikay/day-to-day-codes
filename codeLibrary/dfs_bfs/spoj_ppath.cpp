
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
ll a[11111];
bool v[11111];
vvi adj(11110);


void bfs(ll s,ll t)

{
queue<ll>q;
q.push(s);
vector<ll>level(11000,-1);
level[s]=0;
while(!q.empty())
{
    ll y=q.front();
    q.pop();
    for(auto x:adj[y])
    {
        if(level[x]!=-1) continue;
        level[x]=level[y]+1;
        q.push(x);
        if(x==t)
        {cout<<level[x]<<endl;
        return;
        }
    }
}
cout<<"Impossible\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
memset(a,0,sizeof(a));
memset(v,true,sizeof(v));

for(ll i=2;i*i<=11111;i++)
{
    if(v[i])
   { v[i]=true;
     for(ll j=i+i;j<11111;j+=i)
     {
		v[j]=false;
     }
  }
}

ll num[4];
memset(num,0,sizeof(num));
for(ll i=1000;i<10000;i++)
{
  if(v[i])
  {
      ll x=i;
      ll temp=x;
      for(ll j=3;j>=0;j--)
      {
          num[j]=temp%10;
          temp/=10;
      }

      for(ll s=0;s<4;s++)
      {
          ll digit=num[s];
          ll no[4];
          for(ll d=0;d<4;d++)
          no[d]=num[d];
          ll k=0;
          if(s==0)
          k++;
          for(ll z=k;z<=9;z++)
          {if(z!=digit)
            {
              no[s]=z;
              ll y=no[0]*1000+no[1]*100+no[2]*10+no[3]*1;
              if(v[y])
              adj[x].push_back(y);
            }
          }


      }
  }

}
//for(auto x:adj[3739])
//cout<<x<<" ";
ll t;
cin>>t;
while(t--)
{

    ll start,end;
    cin>>start>>end;
    if(start==end)
    cout<<0<<endl;
    else
    bfs(start,end);

}

}
