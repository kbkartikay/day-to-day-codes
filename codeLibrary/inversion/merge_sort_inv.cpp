
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
ll inv_cnt=0;
void merge1(vector<ll>&a,vector<ll>&temp,ll start,ll mid,ll end1)
{
    ll k=start;
    ll i=start;
    ll j=mid+1;
    while((i<=mid)&&(j<=end1))
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
         else
        {
            temp[k++]=a[j++];
            inv_cnt+=mid-i+1;
        }
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=end1)
        temp[k++]=a[j++];
    for(ll d=start;d<=end1;d++)
        a[d]=temp[d];

}
void merge_sort(vector<ll>&a,vector<ll>&temp,ll start,ll end1)
{
    ll mid=(start+end1)/2;
    if(start<end1)
    {
    merge_sort(a,temp,start,mid);
    merge_sort(a,temp,mid+1,end1);
    merge1(a,temp,start,mid,end1);
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

ll t;
cin>>t;
while(t--)
{
ll n;
cin>>n;
vector<ll>a(n,0),temp;

for(ll i=0;i<n;i++)
    cin>>a[i];
temp=a;
inv_cnt=0;
merge_sort(a,temp,0,n-1);
cout<<inv_cnt<<endl;
}
}
