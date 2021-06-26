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
    int n,m,x;
    cin>>n>>m>>x;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)
    {
        int yo;
        cin>>yo;
        a.push_back({yo,i});

    }
    vector<int>ans(n);
    sort(a.begin(),a.end());
    int j=1;
 
    for(int i=0;i<n;i++)
    {
        ans[a[i].second]=j++;
        if(j>m)j=1;
    }
    cout<<"YES\n";
    for(auto x : ans)cout<<x<<" ";
    cout<<endl;    
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