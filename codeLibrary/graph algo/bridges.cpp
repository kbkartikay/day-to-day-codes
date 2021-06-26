
/*
#######################################################
#    Note to myself : It's all going to be daijobu    #
#######################################################
*/

#include <bits/stdc++.h>
using namespace std;

//Optimizations
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//save time
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f

//loops
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

//vectors
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define pb 	push_back
#define vvi vector<vi>
#define vvll vector<vll>
//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//fast I/O
#ifndef _WIN32
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define gc getchar
#define pc putchar

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=111111;
vll adj[MAXN],tin,low;
bool visited[MAXN];
ll timer;
void dfs(ll v,ll p=-1)
{
    visited[v]=true;

    tin[v]=low[v]=timer++;
    for(auto x: adj[v])
    {
        if(x==p) continue;
        if(visited[x])
        {
            low[v]=min(low[v],tin[x]);
        }
        else{
            dfs(x,v);
            low[v]=min(low[v],low[x]);
            if(tin[v]<low[x])
            {
                cout<<v<<" "<<x<<endl;
            }
        }
    }
}
//Main function
int main(){
    IOS;
    TIE;
 ll t;
 cin>>t;
 while(t--)
 {
     timer=0;
     ll n,e;
     cin>>n>>e;
     for(ll i=0;i<e;i++)
     {
         ll x,y;
         cin>>x>>y;
         adj[x].pb(y);
         adj[y].pb(x);

     }
     memset(visited,false,sizeof(visited));
     tin.assign(n+1,-1);
     low.assign(n+1,-1);
     for(ll i=1;i<=n;i++)
     {
        if(!visited[i])
            dfs(i);

     }
 }

}
