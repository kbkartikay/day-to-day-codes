#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
const long long mod = 1e9 + 7ll ;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int op1=(m-1) + m*(n-1);
    if(op1==k)cout<<"YES\n";
    else cout<<"NO\n";

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