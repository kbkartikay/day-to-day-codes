/*
#######################################################
# Datebayo!  #
#######################################################
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
typedef long long ll;
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
//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
//templates
//Declare all variables and methods needed between this comment and the next one(OCD lol)
const int MAXN=1111111;
vi adj[MAXN];
vi parent(MAXN);
vi size1(MAXN);
int n;
int mn=1e9;
int centre1,centre2,n1,n2;
void dfs(int c,int p=-1)
{
    parent[c]=p;size1[c]=1;
    int mx=0;
    for(auto x : adj[c])
    {
        if(x!=p)
        {
            dfs(x,c);
            size1[c]+=size1[x];
            mx=max(mx,size1[x]);
        }
       
    }
    mx=max(mx,n-size1[c]);
    if(mx<mn)centre1=c,centre2=0,mn=mx;
    else if(mx==mn) centre2=c;
    //cout<<centre1<<" "<<centre2<<endl;

}
void dfs2(int c,int p)
{
    if(adj[c].size()==1)
    {
        n1=c;
        return;
    }
    for(auto x : adj[c])
    {
        if(x!=p)
        dfs2(x,c);
    }
}
void solve()
{
    cin>>n;
    mn=1e9;
    centre1=centre2=0;
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        n1=x;n2=y;
        adj[x].PB(y);adj[y].PB(x);
    }
    dfs(1);
    //cout<<centre1<<" "<<centre2<<endl;
    //cout<<"yp"<<endl;
    if(centre2==0)
    {
      // cout<<"dap"<<endl;
        cout<<n1<<" "<<n2<<endl;
        cout<<n1<<" "<<n2<<endl;
        return;
    }
    if(centre1!=parent[centre2]) swap(centre2,centre1);
    
    dfs2(centre2,centre1);
    n2=parent[n1];
    //cout<<"yo"<<endl;
    cout<<n1<<" "<<n2<<endl;
    cout<<n1<<" "<<centre1<<endl;

}
//Main function
//better impplementation?
// do all things and variable in the if condition of that case only
//dont rely on them repeating or having a certain value.
//doesnt matter if we assign again
//multiple element occurences check, non unique impact
//check overflow
//edge case, 0,1 etc
// see constraints, dumb bruteforce
// what are your assumptions in code? are they right?
//keep checking and progressing!
int main(){
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
   
