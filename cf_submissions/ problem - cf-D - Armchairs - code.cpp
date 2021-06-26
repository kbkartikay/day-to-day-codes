#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
#define PI   3.141592653593
const long long mod = 1e9 + 7ll ;
#define EPS  0.000000001
#define INF  0X3f3f3f3f
/*
cool dp problem but to get to dp first we need to prove
something
let e1...ek be all k ending positions//sorted by position
let s1....sk2 be all k2 starting positions//sorted by position
now if we match s1 to some ec we need to then match
s2 to some e>ec. this is the crux of why the dp works or 
can be constructed in the first place
why is this true?
s1,s2 .... e1,e2 or e1,e2.... s1,s2 here both go to right or left
easy to see by drawing line segments that it soesnt matter which connects
they are interchangable.
but when we have e1....s1s2...e2 now its better to connect 
s1 to e1 and s2 to e2(not vice versa)
can be easily seen by drawing line segments of connection

now we can formulate dp state
dp(i,j) matching ith 1 position to jth 0 position or not
op1= dp(i,j+1)// dont chose this zero as ending position for i, given
above proof no other 1 will chose is either
op2= abs(pos(i)-pos(j))+ dp(i+1,j+1) chossing this zero, no other further 1 could possibly 
have chosen a past zero now( proved as above)
dp(i,j)=min(op1,op2);
*/
vector<int>ones,zeros;
int dp[5007][5007];
int state(int i,int j)
{
    if(i==ones.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if((ones.size()-i)>(zeros.size()-j)) return INF;
    dp[i][j]=min(state(i,j+1),state(i+1,j+1)+abs(ones[i]-zeros[j]));
    return dp[i][j];
}

void solve()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      if(x==0)zeros.push_back(i);
      else ones.push_back(i);
  }
  memset(dp,-1,sizeof(dp));
   cout<<state(0,0)<<endl;
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

