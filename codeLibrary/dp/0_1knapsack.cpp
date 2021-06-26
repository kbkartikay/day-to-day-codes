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
ll dp[107][1007];
ll ans(vector<ll>&w,vector<ll>&c,ll n,ll W)
{
    if(n==0||W==0)
        return 0;
    if(dp[n][W]==-1)
    {
    if(w[n-1]<=W)
        dp[n][W]= max(c[n-1]+ans(w,c,n-1,W-w[n-1]),ans(w,c,n-1,W));
    else
        dp[n][W]= ans(w,c,n-1,W);

    }
    return dp[n][W];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ll n;
memset(dp,-1,sizeof(dp));
cin>>n;
vector<ll> w(n),c(n);
for(ll i=0;i<n;i++) cin>>w[i];
for(ll i=0;i<n;i++) cin>>c[i];
ll W;
cin>>W;
cout<<ans(w,c,n,W)<<endl;

}
