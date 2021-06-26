
#include<bits/stdc++.h>
#define m 10000007
using namespace std;
#define ll long long
ll expo(ll a,ll b)
{
    if(b==0)
        return 1;
    else
    {


    if(b&1==0)
    return expo((a*a)%m,b/2);
    else{
        return a*expo((a*a)%m,(b-1)/2)%m;
    }
    }
}
int main()
{
std::ios::sync_with_stdio(false);

cout<<expo(4,3);
}
