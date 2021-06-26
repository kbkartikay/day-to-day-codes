#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//Constants
#define PI   3.141592653593
const long long mod = 1e9 + 7ll ;
#define EPS  0.000000001
#define INF  1e18

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int mi=INF;
    int maxi=-1;
    for(int i=1;i<=n;i++)
    {
        mi=min(mi,a[i]);
        maxi=max(maxi,a[i]);
    }
    
    //cout<<mi<<endl;
    
    int num;
    for(int i=maxi;i<=2000000007;i++)
    {
        if(gcd(i,mi)==1)
        {
            num=i;
            break;
        }
    }
    int curr=num;
    cout<<n-1<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<1<<" "<<i<<" "<<min(a[1],a[i])<<" "<<curr<<endl;
        a[1]=min(a[1],a[i]);
        curr++;
    }
}

int32_t main()
{
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