/*
#######################################################
#   Konichiwa stalker san!  #
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

//policy based data structure
// #include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=0;
 ll dp[107][1007];
 ll ans(vector<ll>&a,ll n,ll k)
 {
     for(ll i=0;i<=n;i++)
     {
         for(ll j=0;j<=k;j++)
         {
             if(i==0)dp[i][j]=0;
             if(j==0)dp[i][j]=1;
             if(i!=0&&j!=0)
             {
                 if(a[i]<=j)
                 dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j];
                 else
                 dp[i][j]=dp[i-1][j];
             }
         }
     }
     return dp[n][k];
 }
//Main function
int main(){
    IOS;
    TIE;
 ll n;
 cin>>n;
 vector<ll>a(n+1);
 for(ll i=1;i<=n;i++) cin>>a[i];
 ll k;
 cin>>k;
 cout<<ans(a,n,k);
}
