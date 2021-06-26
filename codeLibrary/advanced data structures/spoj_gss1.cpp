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
const int MAXN=77777;
ll a[MAXN];
typedef struct frat
{
    ll sum,prefix,sufix,ans;
}node;
node insert_node(ll val)
{
    node n;
    n.sum=n.prefix=n.sufix=n.ans=val;
    return n;
}
node tree[4*MAXN];
node operate(node l,node r)
{
    node ans1;
    ans1.sum=l.sum+r.sum;
    ans1.prefix=max(l.prefix,l.sum+r.prefix);
    ans1.sufix=max(r.sufix,l.sufix+r.sum);
    ans1.ans=max(max(l.ans,r.ans),l.sufix+r.prefix);
    return ans1;
}
void create(ll v,ll tl,ll tr)
{
   if(tl==tr)
        tree[v]=insert_node(a[tl]);
   else
   {
       ll mid=(tl+tr)/2;
       create(2*v,tl,mid);
       create(2*v+1,mid+1,tr);
       tree[v]=operate(tree[2*v],tree[2*v+1]);
   }

}
node query(ll v,ll tl,ll tr,ll left, ll right)
{
    if(left>right)
        return insert_node(0);
    else if(tl==left&&tr==right)
        return tree[v];
    else
    {
        ll mid=(tl+tr)/2;
        return operate(query(2*v,tl,mid,left,min(right,mid)),query(2*v+1,mid+1,tr,max(mid+1,left),right));
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//cout<<"yo";
ll n;
cin>>n;
//cout<<"yo";
for(ll i=0;i<n;i++) cin>>a[i];
//cout<<"yo";
create(1,0,n-1);
//cout<<"yo";
//for(ll i=0;i<n;i++) cout<<tree[i].ans<<" ";
ll q;
cin>>q;
while(q--)
{

    ll x,y;
    cin>>x>>y;
    x--;y--;
    node isthisanswer;
    isthisanswer=query(1,0,n-1,x,y);
    cout<<isthisanswer.ans<<endl;
}

}
