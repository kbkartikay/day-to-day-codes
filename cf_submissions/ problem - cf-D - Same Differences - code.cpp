#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//Constants
#define PI   3.141592653593
const long long mod = 1e9 + 7ll ;
#define EPS  0.000000001
#define INF  0X3f3f3f3f
void solve()
{
    int n;
    cin>>n;
    map<int,int>mp;
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x-i]++;

    }
    int ans=0;
    for(auto x : mp)
    {

        ans+=((x.second)*(x.second-1))/2;
    }
    cout<<ans<<endl;
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