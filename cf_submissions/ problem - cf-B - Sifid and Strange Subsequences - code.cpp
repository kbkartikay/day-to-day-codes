#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
#define PI   3.141592653593
const long long mod = 1e9 + 7ll ;
#define EPS  0.000000001
#define INF  0X3f3f3f3f



void solve()
{
    int n;
    cin>>n;
    int cnt=0;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int min1=INF;
    vector<int>b;
    int flag=0;
    for(auto x : a)
    {
        if(x<=0)b.push_back(x);
        else flag=1;
    }
    sort(b.begin(),b.end());
    if(b.size()<2)
    {
        if(flag && (b.size()==1))cout<<2<<endl;
        else cout<<1<<endl;
        return;
    }
    int n1=(int)b.size();
    int flag2=0;
    for(int i=1;i<n1;i++)
    {
        min1=min(min1,abs(b[i]-b[i-1]));
    }
    for(auto x : a)
    {
        if((x>0) && (x<=min1))flag2=1;
    }
    if(flag2)cnt++;
    cout<<cnt+b.size()<<endl;
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

