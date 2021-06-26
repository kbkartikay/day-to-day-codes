#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define N 77777
#define Q 300000
#define num 1000001
ll a[N];
struct node
{
    ll l,r,i;
}q[Q];
ll freq[num];
#define  block 277
bool mo(node q1,node q2)
{
    if(q1.l/block!=q2.l/block)
        return q1.l/block<q2.l/block;
    return q1.r<q2.r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
ll n;
scanf("%lld",&n);
ll d;
scanf("%lld",&d);
for(ll i=0;i<d;i++)
{
  scanf("%lld%lld",q[i].l,q[i].r);
  q[i].l--;
  q[i].r--;
  q[i].i=i;
}

}
