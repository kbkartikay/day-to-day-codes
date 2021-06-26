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
const int MAXN=5007;

int dx[3]={-1,0,1};
int dy[3]={-1,0,1};
void solve()
{
    
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vi b(n);
    if(n<=2)
    {
        cout<<0<<endl;
        return;
    }
    int ans=INT_MAX;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int x=a[0]+dx[i];
            int y=a[1]+dy[j];
            int diff=y-x;
            int cnt=0;
            if(j!=1)cnt++;
            if(i!=1)cnt++;
            b[0]=x;
            b[1]=y;
            int check=1;
            for(int k=2;k<n;k++)
            {
                b[k]=b[k-1]+diff;
                if(abs(a[k]-b[k])>1)check=0;
                cnt+=abs(a[k]-b[k]);
            }
            if(check)
            ans=min(ans,cnt);
        }
    }
    if(ans==INT_MAX)cout<<-1<<endl;
    else
    cout<<ans<<endl;

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
   
