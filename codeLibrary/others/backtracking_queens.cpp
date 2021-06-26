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
const int MAXN=111111;
int a[8][8];
int ways=0;
vector<bool>vis1(MAXN,false),vis2(MAXN,false),vis3(MAXN,false);
void queens(int row)
{
    if(row==8)//base
    {
        ways++;
    }
    else
    {
        for(int j=0;j<8;j++)
        {
            if(a[row][j] && !vis1[j] && !vis2[row+j] && !vis3[8-(row-j)])
                {
                    
                    vis1[j]=vis2[row+j]=vis3[8-(row-j)]=true;
                    queens(row+1);
                    vis1[j]=vis2[row+j]=vis3[8-(row-j)]=false;
                }
        }
    }
    
} 
void solve()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            char x;
            cin>>x;
            if(x=='.') a[i][j]=1;
            else a[i][j]=0;
 
        }
    }
    queens(0);
    cout<<ways<<endl;
 
}

int main(){
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
