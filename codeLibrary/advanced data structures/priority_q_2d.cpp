
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n) for (ll i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
typedef struct adsas
{
    int x,y;
}points;
bool cmp(points a,points b)
{
    return a.x<b.x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    points p[2];
    p[0].x=5;
    p[0].y=3;
    p[1].x=3;
    p[1].y=7;
    p[2].x=1;
    p[2].y=2;
    priority_queue<points,vector<points>,cmp>pq;
    pq.push(p[0]);
    pq.push(p[1]);
    pq.push(p[2]);
    while(!pq.empty())
    {
        points k=pq.top()
        cout<<k.x<<" "<<k.y<<endl;
        pq.pop();
    }



}
