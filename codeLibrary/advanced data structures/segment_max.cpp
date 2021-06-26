
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
const int MAXN=50000;
ll a[MAXN];
ll tree[4*MAXN];
void build(ll v, ll tl, ll tr)
{
    if(tl==tr)
    tree[v]=a[tl];
    else{
        ll mid= (tr+tl)/2;
        build(2*v,tl,mid);
        build(2*v+1,mid+1,tr);
        tree[v]=max(tree[2*v],tree[2*v+1]);
    }

}
ll max_calc(ll v,ll tl,ll tr,ll left,ll right)
{
    if(left>right)
        return 0;
    else if(left==tl&&right==tr)
        return tree[v];
    else
    {
        ll mid=(tr+tl)/2;
        return max(max_calc(2*v,tl,mid,left,min(mid,right)),max_calc(2*v+1,mid+1,tr,max(left,mid+1),right));
    }

}
void update(ll v,ll tl,ll tr,ll pos,ll value)
{
    if(tl==tr)
      tree[v]=value;
    else
    {
        ll mid=(tl+tr)/2;
        if(pos<=mid) update(2*v,tl,mid,pos,value);
        else         update(2*v+1,mid+1,tr,pos,value);
        tree[v]=max(tree[2*v],tree[2*v+1]);

    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ll n;
cin>>n;
for(ll i=0;i<n;i++) cin>>a[i];

build(1,0,n-1);
for(ll i=0;i<2*n;i++)cout<<tree[i]<<" ";
cout<<endl;
ll q;
cin>>q;
while(q--)
{
    ll x,y;
    cin>>x>>y;
    cout<<max_calc(1,0,n-1,x,y)<<endl;
    update(1,0,n-1,3,10);
}


}
