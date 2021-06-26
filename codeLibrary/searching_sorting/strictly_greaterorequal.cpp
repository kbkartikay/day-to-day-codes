
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

ll majilower_bound(ll n,vi &a)
{
    ll l=0,r=a.size()-1;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(n==a[mid])
        {
            l=mid;
            r=mid;
            break;
        }
        if(n<a[mid])
        {
            r=mid-1;
        }
        if(n>a[mid]) l =mid+1;
    }
    if(l<a.size())
    return a[l];
    else return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

vi a={2,3,5,6,8,10,12};
ll n;
cin>>n;
cout<<majilower_bound(n,a);

}
