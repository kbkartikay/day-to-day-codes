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

void solve()
{
    int n;
    cin>>n;
    vi last_pos(n+1),a(n+1);
    vi seg(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    for(int i=1;i<=n;i++)
    {
        int seg_size=i-last_pos[a[i]];
        if(seg_size > seg[a[i]]) seg[a[i]]=seg_size;
        last_pos[a[i]]=i;

    }
    for(int i=1;i<=n;i++)
    {
        int seg_size=n+1-last_pos[a[i]];
        if(seg_size > seg[a[i]]) seg[a[i]]=seg_size;
    }
   // for(auto x : seg) cout<<x<<" ";
    //cout<<endl;
    vi ans(n+1,INT_MAX);
    for(int i=1;i<=n;i++)
    {
        int seg_size=seg[a[i]];
        if(ans[seg_size]>a[i])ans[seg_size]=a[i];
    }
    //for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=n;i++)
    {
        

            ans[i]=min(ans[i],ans[i-1]);
        
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==INT_MAX)cout<<-1<<" ";
        else
        cout<<ans[i]<<" ";
    }   
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
   
