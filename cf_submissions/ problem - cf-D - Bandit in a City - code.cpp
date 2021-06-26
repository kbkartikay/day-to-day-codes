/*
#######################################################
# Its all going to be daijobu  #
#######################################################
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
#define int long long
//typedef int ll;
#define all(a) a.begin(),a.end()
//Constants
#define PI   3.141592653593
#define mod  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f
//loops
#define REP(i,n)        for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)
//STL
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define PB push_back
#define vvi vector<vi>
#define vvll vector<vll>
#define F first
#define S second
//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//templates

//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=2e5+7;
vi adj[MAXN];
int sum[MAXN];
int leaf[MAXN];
int a[MAXN];
void dfs(int u,int p=-1)
{
    if(adj[u].size()==0)
    {
        sum[u]=a[u];
        leaf[u]=1;
        return;
    }
    sum[u]=a[u];
    for(auto x : adj[u])
    {
        if(u!=p)
        {

            dfs(x,u);
            leaf[u]+=leaf[x];
            sum[u]+=sum[x];
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].PB(i);
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1);
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        int temp=sum[i]/leaf[i];
        if(sum[i]%leaf[i]!=0)temp++;
        ans=max(ans,temp);
    }
    cout<<ans<<endl;

}

int32_t main(){
IOS;
TIE;     
#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
#endif   

solve();

}
   
