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
//typedef long long ll;
#define all(a) a.begin(),a.end()
//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
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
vpi adj[MAXN];
struct dokla
{
    bool operator()(pi a,pi b)
    {
        if(a.F==b.F)return a.S<b.S;
        return a.F<b.F;
    }
};
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].PB({y,z});
 
    }
    vi cost1(n+1,LLONG_MAX);
    cost1[1]=0;
    priority_queue<pi>q;
    q.push({0,1});
    vector<bool>vis(n+1,false);
    vi p(n+1,0);
 
    while(!q.empty())
    {
        int v=q.top().S;
        
        q.pop();
        if(vis[v])continue;
        vis[v]=true;
        for(auto x : adj[v])
        {
            int edge=x.S;
            int to=x.F;
            if(cost1[v]+edge<cost1[to])
            {
                cost1[to]=cost1[v]+edge;
                q.push({-cost1[to],to});
                p[to]=v;    
            }
        }
    }
    int ans=-1;
    int pos=n;
    //for(int i=1;i<=n;i++)cout<<p[i]<<" ";
    //cout<<endl;
   // for(int i=1;i<=n;i++)cout<<cost1[i]<<" ";
    //cout<<endl;
    while(p[pos])
    {
        ans=max(ans,abs(cost1[pos]-cost1[p[pos]]));
        pos=p[pos];
    }
    int sub=ans-ans/2;
    //cout<<cost1[n]-sub;
    for(int i=1;i<=n;i++)cout<<cost1[i]<<" ";
 
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
