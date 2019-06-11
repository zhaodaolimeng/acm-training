/**
 * 10D. LCIS
 *
 * 这个答案非常好，但是也很绕：
 * http://codeforces.com/contest/10/submission/7325338
 * http://blog.fly2best.com/algorithm/2013/05/11/longges-common-increasing-subsequence/
 */

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int dp[510][510];
//int px[510][510], py[510][510];
//int a[510], b[510];
//int n, m, t;
//
//void method_o4(){
//    for(int i=0; i<n; i++){
//        for (int j = 0; j < m; ++j) {
//
//            if(a[i] != b[j]){
//                dp[i][j] = 0;
//            }else{
//                for(int ii=0; ii<i;ii++){
//                    for(int jj=0; jj<j; jj++){
//                        dp[i][j] = max(dp[i][j], dp[ii][jj] + 1);
//                    }
//                }
//            }
//        }
//    }
//}
//
//void method_o3(){
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            if(a[i] != b[j]){
//                dp[i][j] = 0;
//            }else{
//                for(int jj=0; jj<j ;jj++){
//                    if(b[jj]<b[j])
//                        dp[i][j] = max(dp[i][j], dp[i-1][jj] + 1);
//                    // 这个分支里面b[j]==a[i]
//                    // 所以b[jj]<b[j]等价于b[jj]<a[i]，最大值可以预计算
//                }
//            }
//        }
//    }
//}
//
//void method_o2(){
//    for(int i=0; i<n; i++){
//        int nlen = 0;
//        for(int j=0; j<m; j++){
//            dp[i][j] = dp[i-1][j];
//            if(b[j]<a[i] && dp[i-1][j]>nlen)
//                nlen = dp[i-1][j];
//            if(b[j]==a[i])
//                dp[i][j] = nlen + 1;
//        }
//    }
//
//}
//
//void trace(){
//
//
//}
//
//int main() {
//
//    int nlen, maxv = 0, x, y;
//
//    cin>>n;
//    for (int i = 1; i < 1+n; ++i) cin>>a[i];
//    cin>>m;
//    for (int i = 1; i < 1+m; ++i) cin>>b[i];
//
//    for(int i=1; i<=n; i++){
//        nlen = 0;
//        for(int j=1; j<=m; j++){
//            dp[i][j] = dp[i-1][j];
//
//            if(b[j]<a[i] && dp[i-1][j]>nlen)
//                nlen = dp[i-1][j];
//            if(b[j]==a[i])
//                dp[i][j] = nlen + 1;
//            maxv = max(maxv, dp[i][j]);
//        }
//    }
//    if(maxv != 0){
//        cout<<maxv<<endl;
//    }else{
//        cout<<0<<endl;
//    }
//    return 0;
//}

#include <iostream>
using namespace std;

const int MAXN = 1000;

int A[MAXN], B[MAXN], P[MAXN], F[MAXN], ret[MAXN];
int N, M;

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++ i) cin >> A[i];
    cin >> M;
    for (int i = 1; i <= M; ++ i) cin >> B[i];
    for (int i = 1; i <= N; ++ i) {
        int best = 0;
        for (int j = 1; j <= M; ++ j) {
            if (A[i] == B[j] && F[best] + 1 > F[j])
                F[j] = F[best] + 1, P[j] = best;
            else if (B[j] < A[i] && F[j] > F[best]){
                // F这个数组保留了每一行中的最大值
                // best存储了A[i]>B[j]中的B[j]的最大值，这样当A[i]==B[j]时，其实是B[j]>B[j']的一个序列
                best = j;
                // best是为了在这一行获取一个升序序列
            }
            cout<<F[j]<<"--"<<best<<"\t";
        }
        cout<<endl;
    }

    int best = 0, cnt = 0;
    for (int i = 1; i <= M; ++ i) {
        if (F[best] < F[i]) best = i;
    }
    for (int i = best; i; i = P[i]) ret[cnt ++] = B[i];
    cout << cnt << endl;
    for (int i = cnt - 1; i >= 0; -- i) {
        cout << ret[i] << " \n"[i == 0];
    }
    return 0;
}

/*

5
1 0 2 0 3
5
5 1 2 3 0
0--0	1--0	0--0	0--0	0--0
0--0	1--0	0--0	0--0	1--0
0--0	1--2	2--2	0--2	1--2
0--0	1--0	2--0	0--0	1--0
0--0	1--2	2--3	3--3	1--3
3
1 2 3

 */