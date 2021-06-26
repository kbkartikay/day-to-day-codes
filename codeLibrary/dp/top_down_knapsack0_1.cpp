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
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=W;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else
            {
                if(w[i]<=j)
                    dp[i][j]=max((c[i]+dp[i-1][j-w[i]]),(dp[i-1][j]));
                else dp[i][j]=dp[i-1][j];
            }
        }

    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ll n;
memset(dp,-1,sizeof(dp));
cin>>n;
vector<ll> w(n+1),c(n+1);
for(ll i=1;i<=n;i++) cin>>w[i];
for(ll i=1;i<=n;i++) cin>>c[i];
ll W;
cin>>W;
ans(w,c,n,W);
cout<<dp[n][W]<<endl;

}

