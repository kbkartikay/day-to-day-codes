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
vector<int>p;
void solve()
{
    ll n,m;
    cin>>m>>n;
    ll cnt=0;
    vector<bool>check(n-m+1,true);
    for(ll i=0;p[i]*p[i]<=n;i++)
    {
        ll prime=p[i];
        ll lower=ceil((double)m/prime)*prime;

        if(prime>=m)
            lower+=prime;
        if(lower<=n)
        {

            for(ll j=lower;j<=n;j+=prime)
                check[j-m]=false;

        }
    }
    for(ll i=0;i<check.size();i++)
    {
        if(check[i])
            cout<<i+m<<endl;
    }

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

ll k=100001;
vector<bool>isprime(k,true);

for(ll i=2;i<=k;i++)
{
    if(isprime[i])
    {
        p.push_back(i);
        for(ll j=i*i;j<=k;j+=i)
        isprime[j]=false;


    }
}

ll t;
cin>>t;
while(t--)
{

    solve();
}


}
