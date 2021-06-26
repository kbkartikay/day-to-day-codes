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
vi adj[MAXN];
vi tin(MAXN),tout(MAXN);
vi parent(MAXN);
vi depth(MAXN);
int timer=0;
void dfs(int u,int p=-1,int dep=0)
{
    parent[u]=p;
    tin[u]=timer++;
    depth[u]=dep;
    for(auto x :  adj[u])
    {
        if(x!=p)
        {

            dfs(x,u,dep+1);

        }    
    }
    tout[u]=timer++;
}
bool isancestor(int a,int b)
{
    if(tin[a]<=tin[b] && tout[a]>=tout[b])return true;
    return false;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].PB(y);adj[y].PB(x);

    }
    dfs(1);
    while(m--)
    {
        int num;
        cin>>num;
        vi a(num);
        int max1=-1;
        for(int i=0;i<num;i++)
        {
            cin>>a[i];
            if(a[i]!=1)
            a[i]=parent[a[i]];
            
        }
        int vp;
        for(int i=0;i<num;i++)
        {
            if(depth[a[i]]>max1)
            {
                max1=depth[a[i]];
                vp=a[i];
            }
        }

        int flag=0;
        for(int i=0;i<num;i++)
        {
            if(!isancestor(a[i],vp) || !isancestor(1,a[i]))
            {
                
                flag=1;
            }
        }
        if(flag)
        {
            cout<<"NO\n";
        }
        else cout<<"YES\n";
        
    }

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
   
