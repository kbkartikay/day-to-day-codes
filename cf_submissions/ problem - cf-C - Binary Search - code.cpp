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
#define mod  1000000007LL
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
int modpower(int a , int b)
{
    if(b == 0)
        return 1ll ;
    int x = modpower(a , b / 2ll) ;
    x = (x * x) % mod ;
    if(b & 1)
        return (x * a) % mod ;
    return (x % mod) ;
}
 
struct combination
{
    vector<int>fact , inv ;
    combination(int sz) : fact(sz + 1) , inv(sz + 1)
    {
        fact[0] = 1ll ;
        inv[0] = 1ll ;
        for(int i = 1 ; i <= sz ; ++i)
            fact[i] = (fact[i-1] * i) % mod ;
        inv[sz] = modpower(fact[sz] , mod - 2ll) ;
		for(int i = sz-1; i >= 1; --i)
		    inv[i] = (inv[i+1] * (i+1)) % mod;
    }
    int choose(int n , int k) const
    {
        if(k < 0 || n < k)
            return 0 ;
        return ((((fact[n] * inv[k]) % mod) * inv[n - k]) % mod) ;
    }
};
//Declare all variables and methods needed between this comment and the next one(OCD lol)

const int MAXN=1007;
combination cmb(MAXN);

int ls=0;int grt=0;
int n,x,pos;
void simulate()
{
    int l=0;int r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(mid<=pos)
        {
            l=mid+1;
            if(mid!=pos)ls++;
        
        }
        else
        {
            r=mid;
            grt++;
        }
        
    }

}
int npr(int a,int b)
{
    return (cmb.choose(a,b)*cmb.fact[b])%mod;
}
void solve()
{
    cin>>n>>x>>pos;
    simulate();
    int km=x-1;
    int zyada=n-x;
    int ans=npr(km,ls)*npr(zyada,grt)%mod * cmb.fact[n-1-ls-grt]%mod;
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
   
