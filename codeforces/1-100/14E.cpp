// http://codeforces.com/contest/14/submission/79670865

#include<cstdio>
#define For(i,_,__) for(int i=_;i<=__;i++)

int n,t,ans,f[21][5][5][11][11];


/*
还有一种递推方式是
dp[21][11][5][2]
表示在剩余a个空格、剩余b个驼峰、当前高度为c、当前趋势是上升/下降状态的可能状况数
*/

int main() {
	scanf("%d%d",&n,&t);
	For(i,1,4)For(j,1,4)f[2][i][j][0][0]=i!=j;
	For(i,3,n)For(j,1,4)For(k,1,4)
	For(x,0,t)For(y,0,t)For(l,1,4)if(k!=l)
		f[i][k][l][x+(j<k&&k>l)][y+(j>k&&k<l)]+=f[i-1][j][k][x][y];
	For(i,1,4)For(j,1,4)ans+=f[n][i][j][t][t-1];
	printf("%d\n",ans);
}

