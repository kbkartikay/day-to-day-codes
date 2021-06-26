//given a path of size n with up down left right. find min loop

#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
int main()
{
std::ios::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
{


ll n;

string s;
cin>>n>>s;
ll l=-1,r=n;
pair<int,int> pos ={0,0};
map<pair<int,int>,int> sugoi;
sugoi[pos]=0;
for(ll i=0;i<n;i++)
{
    if(s[i] == 'U') pos.second++;
    if(s[i] == 'D') pos.second--;
    if(s[i]== 'R') pos.first++;
    if(s[i]=='L') pos.first--;
    if(sugoi.count(pos))
    {
        if((i+1)-sugoi[pos]<r-l)
        {
            l=sugoi[pos];
            r=i+1;
        }
    }

    sugoi[pos]=i+1;
}
if(l==-1)
    cout<<-1<<endl;
else cout<<l+1<<" "<<r<<endl;
}}
