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
    vi b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a.begin(),a.end());
    if(a[0]==a[n-1])
    {
        cout<<-1<<endl;
        return;
    }
    int max1=a[n-1];
    int pos;
    for(int i=0;i<n;i++)
    {
        if(b[i]==max1)
        {
            if(i+1<n)
            {
                if(b[i+1]<b[i])
                {
                    pos=i;
                    break;
                }
            }
            if(i-1>=0)
            {
                if(b[i-1]<b[i])
                {
                    pos=i;
                    break;
                }
            }
        }
    }
    cout<<pos+1<<endl;
   
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

int t;
cin>>t;
while(t--)solve();

}
   
