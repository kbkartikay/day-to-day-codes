
#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll euclid_gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else{
        return euclid_gcd(b,a%b);
    }

}
int main()
{
std::ios::sync_with_stdio(false);
ll ans=euclid_gcd(6,8);
cout<<ans;

}
