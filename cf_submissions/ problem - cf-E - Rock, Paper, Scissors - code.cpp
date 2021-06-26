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
//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=3e5+7;
int winning_map(vi &a,vi &b)
{
    return min(a[0],b[1]) + min(a[1],b[2]) + min(a[2],b[0]);
}
void solve()
{
    int n;
    cin>>n;
    vi a(3),b(3);
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];
    int ans2=winning_map(a,b);
    int ans1=INT_MAX;
    vpi suka(6);
    suka[0]={0,0};suka[1]={0,2};
    suka[2]={1,1};suka[3]={1,0};
    suka[4]={2,2};suka[5]={2,1};
    do
    {
        vi a1=a;
        vi b1=b;
        for(int i=0;i<6;i++)
        {
            int subtr=min(a1[suka[i].F],b1[suka[i].S]);
            a1[suka[i].F]-=subtr;
            b1[suka[i].S]-=subtr;
        }
        ans1=min(ans1,winning_map(a1,b1));
    } while (next_permutation(suka.begin(),suka.end()));
    cout<<ans1<<" "<<ans2;
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

 solve();


}
   
