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
bool dp[107][1007];
bool ans(vector<ll>&arr,ll n,ll k)
{
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=k;j++)
        {
            if(i==0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
            if(i!=0&&j!=0)
            {
                if(arr[i]<=j)
                dp[i][j]=(dp[i-1][j-arr[i]])||(dp[i-1][j]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
ll n;
cin>>n;
vector<ll>arr(n+1);
for(ll i=1;i<=n;i++) cin>>arr[i];
ll k; cin>>k;
if(ans(arr,n,k)) cout<<"YAS\n";
else cout<<"nah nigga\n";


}
