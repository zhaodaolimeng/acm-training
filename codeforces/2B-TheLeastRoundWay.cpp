#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<bitset>
using namespace std;
#define REPF( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define REP( i , n ) for ( int i = 0 ; i < n ; ++ i )
#define CLEAR( a , x ) memset ( a , x , sizeof a )
typedef long long LL;
typedef pair<int,int>pil;
const int INF=0x3f3f3f3f;
const int maxn=1010;
int dp[maxn][maxn][2];
int path[maxn][maxn][2];
int mp[maxn][maxn][2];
int n;
void print(int i,int j)
{
    if(i==1&&j==1)
        return ;
    print(path[i][j][0],path[i][j][1]);
    if(i-path[i][j][0]==1&&j==path[i][j][1]) printf("%c",'D');
    else printf("%c",'R');
}
int main()
{
    int x,cnt1,cnt2,temp;
    while(~scanf("%d",&n))
    {
        REPF(i,1,n)
        {
            REPF(j,1,n)
            {
                scanf("%d",&x);
                cnt1=cnt2=0;temp=x;
                while(temp%2==0)
                {
                    temp/=2;
                    cnt1++;
                }
                while(x%5==0)
                {
                    x/=5;
                    cnt2++;
                }
                mp[i][j][0]=cnt1;
                mp[i][j][1]=cnt2;
            }
        }
        CLEAR(dp,INF);
        dp[1][1][0]=mp[1][1][0];
        dp[1][1][1]=mp[1][1][1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=0;k<2;k++)//0:2 1:5
                {
                    if(i>1&&dp[i][j][k]>dp[i-1][j][k]+mp[i][j][k])
                    {
                        dp[i][j][k]=dp[i-1][j][k]+mp[i][j][k];
                        path[i][j][0]=i-1;path[i][j][1]=j;
                    }
                    if(j>1&&dp[i][j][k]>dp[i][j-1][k]+mp[i][j][k])
                    {
                        dp[i][j][k]=dp[i][j-1][k]+mp[i][j][k];
                        path[i][j][0]=i;path[i][j][1]=j-1;
                    }
                }
            }
        }
        printf("%d\n",min(dp[n][n][0],dp[n][n][1]));
        print(n,n);
//        puts("");
    }
    return 0;
}