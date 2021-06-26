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
ll range_sum(ll *bit,ll index)
{
    ll sum=0;

    for(ll i=index;i>0;i-=i&(-i))
        sum+=bit[i];


    return sum;
}
void update(ll *bit,ll n,ll value,ll index)
{
    index++;
    for(ll i=index;i<=n;i+=i&(-i))
        bit[i]+=value;

}
ll *create_bit(ll *arr,ll n)
{
    ll *bit=new ll[n+1];
    memset(bit,0,sizeof(bit));
    for(ll i=0;i<n;i++)
    {
        update(bit,n,arr[i],i);
    }
    return bit;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
ll arr[]={2,7,3,1,4,6,8};
ll n=sizeof(arr)/sizeof(arr[0]);
ll *bit=create_bit(arr,n);
for(ll i=1;i<n+1;i++)
    cout<<bit[i]<<" ";
cout<<endl;
ll l=1,r=5;//l inclusive and r inclusive
ll sum1=range_sum(bit,r+1);
ll sum2=range_sum(bit,l);
cout<<sum1-sum2;

}

