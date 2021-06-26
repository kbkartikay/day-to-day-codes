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
//for usaco

//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=2007;
bool check(vi &a,vi &b)//function to see if vector a==b, 
//basically comparing if two sets have the same elements
//hence if same elements with same freq are there 
//you can say that their exist a permutation(of positions!) where a==b
{
    sort(b.begin(),b.end());//can sort a also but its always sorted
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])return false;
    }
    return true;
}

void solve()
{
 int n,m;
 cin>>n>>m;
 vi a(n),b(n);
 for(int i=0;i<n;i++)cin>>a[i];
 for(int i=0;i<n;i++)cin>>b[i];
 int ans=INT_MAX;
 sort(b.begin(),b.end());//sorting b will make it easier to compare if
 //a==b after (a[i]+x)%m
 
 int num=a[0];//checking possible x against all elements of b compared with first element of a
 // so basically if we find x for a[0] compared to all b[i],thats a possible x;
 //if this possible x can transform a to b(see check function above to check equality of these two sets)
 //then thats our ans
 //it will also be min by default of the way we are calculating candidate,
 //as only 1 candidate exists between 0 and m-1 which is uniquely making equal and is also the minimum
 for(int i=0;i<n;i++)
 {
     int cand=((b[i]+m)-num)%m;//this is our candidate x for bi

     vi temp;
     for(int i=0;i<n;i++)
     {
         temp.PB((a[i]+cand)%m);//simulating stuff as in Q

     }
     if(check(b,temp))//checking equality
     {
         ans=cand;
     }
 }
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
   
