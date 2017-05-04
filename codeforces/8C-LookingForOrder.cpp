/**
 * 每次从一个点的集合中取两个点或一个点，得分为这两个点的距离，求该得分的最小值
 * 以下使用递归的方法求解，需要改写成dp的标准形式
 *
 */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

const int INF = (1<<30);
int n;
int x[25], y[25];
int dp[(1<<24)];
pair<int,int> trace[(1<<24)];


int dist(int a, int b){
    return (x[a]-x[b])*(x[a]-x[b]) + (y[a] - y[b])*(y[a] - y[b]);
}

int min_dist(int mask){

    if(mask == ((1<<(n+1))-2))
        return 0;
    if(dp[mask>>1] != -1) return dp[mask>>1];
    int ans = INF, mask0 = mask, t = 0, first = 0;

    //选择第一个点
    for(int i=1; i<=n; i++){
        if((mask&(1<<i)) == 0){
            mask0 = mask | (1<<i);
            first = i;
            break;
        }
    }
    //选择第二个点
    for(int i=1; i<=n; i++){
        if((mask0&(1<<i)) == 0){
            t = min_dist((mask0 | (1<<i))) + dist(first, i);
            if(t < ans){
                ans = t;
                trace[mask>>1] = make_pair(first, i);
            }
        }
    }

    t = min_dist(mask0) + dist(first, 0); // 有可能某次只选择了一个点
    if(t < ans){
        ans = t;
        trace[mask>>1] = make_pair(first, 0);
    }
    dp[mask >> 1] = ans;
    return ans;
}

void print(int mask){
    if(mask == (1<<n)-1)
        return;
    int u = trace[mask].first, v = trace[mask].second;
    printf("%d %d ",u, v);
    if(v != 0) printf("0 ");
    mask |= (1<<(u-1));
    if(v != 0) mask |= (1<<(v-1));
    print(mask);
}

int main(){

    int ans = 0;
    memset(dp,-1,sizeof(dp));

    cin>>x[0]>>y[0]>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        ans += dist(i, 0);
    }
    cout<<min_dist(0) + ans<<endl;
    printf("0 ");
    print(0);

    return 0;
}

/**
// http://www.cnblogs.com/yohaha/p/5275521.html

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
#define pb(x) push_back(x)
#define ll long long
#define mk(x, y) make_pair(x, y)
#define lson l, m, rt<<1
#define mem(a) memset(a, 0, sizeof(a))
#define rson m+1, r, rt<<1|1
#define mem1(a) memset(a, -1, sizeof(a))
#define mem2(a) memset(a, 0x3f, sizeof(a))
#define rep(i, n, a) for(int i = a; i<n; i++)
#define fi first
#define se second
typedef pair<int, int> pll;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9+7;
const int inf = 1061109567;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int n;
int dp[1<<24], dis[25][25], b[1<<24], ans[500], cnt;
pll a[25];
int main()
{
    int x, y;
    cin>>a[0].fi>>a[0].se;
    cin>>n;
    a[n] = a[0];
    for(int i = 0; i<n; i++) {
        scanf("%d%d", &a[i].fi, &a[i].se);
    }
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=n; j++) {
            dis[i][j] = (a[i].fi-a[j].fi)*(a[i].fi-a[j].fi)+(a[i].se-a[j].se)*(a[i].se-a[j].se);
        }
    }
    mem2(dp);
    dp[0] = 0;
    for(int i = 0; i<(1<<n); i++) {
        if(dp[i]==inf)
            continue;
        for(int j = 0; j<n; j++) {
            if((1<<j&i)==0) {
                for(int k = j; k<n; k++) { //k==j时就会覆盖第一个
                    if((1<<k&i)==0) {
                        int tmp = i|(1<<j)|(1<<k);
                        int d = dis[j][k]+dis[n][j]+dis[n][k];
                        if(dp[tmp]>dp[i]+d) {
                            dp[tmp] = dp[i]+d;
                            b[tmp] = i;
                        }
                    }
                }
                break;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    for(int i = (1<<n)-1; i!=0; i = b[i]) {
        int tmp = b[i]^i;
        ans[cnt++] = 0;
        for(int j = 0; j<n; j++) {
            if((1<<j)&tmp) {
                ans[cnt++] = j+1;
            }
        }
    }
    ans[cnt++] = 0;
    for(int i = cnt-1; i>=0; i--) {
        printf("%d ", ans[i]);
    }
    return 0;
}

 */
