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
const ll max1=1e5;
ll gp[max1+1];
ll x[max1];
ll y[max1];
ll ans;
ll c[2][max1+1];
ll n,m;
void find_divisor(vector<array<ll,2>> &pr,vector<ll> &k, ll i=0,ll x=1)
{
    if(i>=pr.size()||x*pr[i][0]>max1)
    {
        k.push_back(x);
        return;
    }
    for(ll j=0;j<=2*pr[i][1]&&x<=max1;x*=pr[i][0],j++)
    {
        find_divisor(pr,k,i+1,x);
    }
}
void solve_more(ll x[max1],ll y[max1],ll n,ll m)
{
    memset(c,0,sizeof(c));
    for(ll i=0;i<m;i++)
    {
        c[y[i]>0][abs(y[i])]++;
    }
     vector<array<ll,2>> pr;
    for(ll i=0;i<n;i++)
    {
        ll p=abs(x[i]);

        while(p>1)
        {
            ll c=gp[p];ll cnt=0;
            while(p%c==0)
            {
                p=p/c;
                cnt++;
            }
        pr.push_back({c,cnt});

        }
        reverse(pr.begin(),pr.end());

    vector<ll>k;
    find_divisor(pr,k);
    for (ll j:k)
    {
        if(x[i]*x[i]/j<=max1)
        {
        if(c[0][j]&&c[1][x[i]*x[i]/j])
            ans++;
        }
    }
    }
}

void solve()
{

    cin>>n>>m;
    ll zero=0;
   for(ll i=0;i<n;i++)
   {
       cin>>x[i];
       if(!x[i])
       {
           zero=1;
           i--;
           n--;
       }
   }
   for(ll i=0;i<m;i++)
   {
      cin>>y[i];
      if(!y[i])
      {
        zero=1;
        i--;
        m--;
      }
   }
   ans=zero*m*n;
   solve_more(x,y,n,m);
   solve_more(y,x,m,n);
   cout<<ans<<endl;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
for(ll i=2;i<=max1;i++)
{
    if(!gp[i])
    {
        for(ll j=0;j<=max1;j+=i)
        {
            gp[j]=i;
        }
    }
}

ll t;
cin>>t;
while(t--)
{
    solve();
}

}
