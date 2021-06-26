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
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    set<int> ans;
    for(int i=0;i<n;i++)
    {
        auto it = ans.lower_bound(a[i]);
        if(it==ans.end())ans.insert(a[i]);
        else 
        {
          ans.erase(it);
          ans.insert(a[i]);
        }
    }
    cout<<ans.size()<<endl;
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
solve();   
}
