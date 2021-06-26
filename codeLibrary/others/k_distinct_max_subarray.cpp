#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
int main()
{
std::ios::sync_with_stdio(false);
ll t;
cin>>t;
while(t--)
{
    ll n,k,unique=0,l=0,start=0,end=0;
    cin>>n>>k;
    vector<int>a(n);
    unordered_map<int,int>f;
    k--;//finding k-1 distint number containing longest subsequence
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++)
    {
        f[a[i]]++;
        if(f[a[i]]==1)
        unique++;
        while(unique>k)
        {
            f[a[l]]--;
            if(f[a[l]]==0)
            unique--;
            l++;
        }
        if(i-l>end-start)
        {start=l; end=i;}

    }
    cout<<end-start+1<<endl;
}

}
