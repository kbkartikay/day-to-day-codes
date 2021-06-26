
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
const int MAXN=77777;
 ll tre[4*MAXN];
 ll a[MAXN];
void build(ll v,ll left,ll right)
 {
     if(left==right)
        tre[v]=a[left];
     else
     {
         ll mid=(left+right)/2;
         build(2*v,left,mid);
         build(2*v+1,mid+1,right);
         tre[v]=tre[2*v]+tre[2*v+1];
     }
 }

ll sum(ll v,ll tl,ll tr, ll left, ll right)
{
    if(left>right)
        return 0;
    else if(left==tl && right==tr)
            return tre[v];
    else
    {
        ll mid=(tl+tr)/2;
    return sum(2*v,tl,mid,left,min(right,mid))+sum(2*v+1,mid+1,tr,max(left,mid+1),right);

    }

}
void update(ll v,ll tl,ll tr, ll pos,ll value)
{
    if(tl==tr)
    tre[v]=value;
    else
    {
        ll mid=(tr+tl)/2;
        if(pos<=mid) update(2*v,tl,mid,pos,value);
        else update(2*v+1,mid+1,tr,pos,value);
        tre[v]=tre[2*v]+tre[2*v+1];
    }


}

//Main function
int main(){
    IOS;
    TIE;
ll n;
cin>>n;
for(ll i=0;i<n;i++)
    cin>>a[i];
build(1,0,n-1);
cout<<sum(1,0,n-1,2,5)<<endl;
update(1,0,n-1,5,11);
cout<<sum(1,0,n-1,2,5)<<endl;
}
