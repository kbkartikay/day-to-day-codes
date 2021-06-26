/*
#######################################################
# Datebayo!  #
#######################################################
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
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
//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//templates
//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=111111;

void solve()
{
    ll n;
    cin>>n;
    ll mul=1;
    vll a(n);
    FOR(i,0,n)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll last=a[n-1];
    if(last==0)
    {
        cout<<0<<endl;
        return;
    }
    if(last<0)
    {
        
        for(int i=n-1;i>=n-5;i--)
        mul*=a[i];
        cout<<mul<<endl;
        return;
    }
    
    if(last>0)
    {
        mul=last;
        ll i=0;ll j=n-2;
        for(int k=0;k<2;k++)
        {
            ll l=a[i]*a[i+1];
            ll r=a[j]*a[j-1];
            if(l>=r)
            {
                mul*=l;
                i+=2;
            }
            else
            {
                mul*=r;
                j-=2;
            }
            
        }
        cout<<mul<<endl;
        return;

    }
}
//Main function
//better impplementation?, mathematical variable use
// general thinking 
// do all things and variable in the if condition of that case only
//dont rely on them repeating or having a certain value.
//doesnt matter if we assign again
//multiple element occurences check, non unique impact
//check overflow
//edge case, 0,1 etc
// see constraints, dumb bruteforce
// what are your assumptions in code? are they right?
//keep checking and progressing!
int main(){
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
   
