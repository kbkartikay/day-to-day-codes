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

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    int flag=0;
    int cnt=0;
    int prev=-3;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
    }
    int pos1=-1;
    int pos2;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])cnt++;
        if(a[i]==a[i-1])pos1=i,pos2=i-1;
    }
   
    if(cnt==0)
    {
        cout<<1<<endl;
        for(int i=0;i<n;i++)cout<<1<<" ";
        cout<<endl;
        return;
    }
   vi ans;
        for(int i=0;i<n;i++)
        {
            if(i%2)ans.PB(1);
            else ans.PB(2);
        }
   
     if(n%2==0 || a[n-1]==a[0])
     {
         cout<<2<<endl;
         for(auto x : ans)cout<<x<<" ";
         cout<<endl;
         
     }  
     else
     {
         if(pos1!=-1 )
         {
            for(int i=pos1;i<n;i++)
            {
                if(i%2)ans[i]=2;
            else ans[i]=1;
            }
                cout<<2<<endl;
         for(auto x : ans)cout<<x<<" ";
         cout<<endl; 
         }    
         else
         {
             ans[n-1]=3;
             cout<<3<<endl;
         for(auto x : ans)cout<<x<<" ";
         cout<<endl;
         }
         
     }
     
      

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
while(t--) solve();

}
   
