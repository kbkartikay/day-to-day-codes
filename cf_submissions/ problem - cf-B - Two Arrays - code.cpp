/*
#######################################################
# Its all going to be daijobu  #
#######################################################
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
//#define int long long
typedef long long ll;
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
struct cmp
{
    bool operator()(pi a,pi b)
    {
        if(a.F<b.F) return true;
        if(a.F>b.F)return false;
        if(a.F==b.F)return a.S<b.S;
    }
};
//policy based data structure
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<pi, null_type,cmp, rb_tree_tag,tree_order_statistics_node_update>

//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=2e5+7;

void solve()
{
    int n,target;
    cin>>n>>target;
    map<int,int>mp0,mp1;
    vi a(n),ans(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int other=target-x;
        if(mp0.find(other)==mp0.end())
        {
            mp0[x]++;
            ans[i]=0;
        }
        else if(mp1.find(other)==mp1.end())
        {
            mp1[x]++;
            ans[i]=1;
        }
        else
        {
             if(mp1[other]<=mp0[other])
             {
                 mp1[x]++;
                 ans[i]=1;
             }
             else
             {
                 mp0[x]++;
                 ans[i]=0;
             }
             
        }
        
    }
    for(auto x : ans)cout<<x<<" ";
    cout<<endl;
}
//Main function
//better impplementation?
// do all things and variable in the if condition of that case only
//dont rely on them repeating or having a certain value.
//doesnt matter if we assign again
//multiple element occurences check, non unique impact
//check overflow
//edge case, 0,1 etc
// see constraints, dumb bruteforce
// what are your assumptions in code? are they right?
//keep checking and progressing!
int32_t main(){
IOS;
TIE;     
#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
#endif   
int t;
cin>>t;
while(t--)
solve();


}
   
