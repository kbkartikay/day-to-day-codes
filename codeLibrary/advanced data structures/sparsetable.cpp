#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
int table[21][1000007];
int n,m;

int logcalc(int num)
{
    int cnt=0;
    for(int i=2;i<=num;i<<=1)
    {
        cnt++;
    }
    return cnt;
}
void build()
{
    int num=logcalc(n);
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<=n-(1<<i);j++)
        {
            table[i][j]=MIN(table[i-1][j],table[i-1][j+(1<<(i-1))]);
        }

    }
}
void solve()
{
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&table[0][i]);
    }
    
   build();
  
    int num=logcalc(n);
    while(m--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        int val=r-l+1;
        val=logcalc(val);
        int ans1=MIN(table[val][l],table[val][r-(1<<val)+1]);
        printf("%d\n",ans1);
    }
}

int main() {



solve();
    
    return 0;
}
