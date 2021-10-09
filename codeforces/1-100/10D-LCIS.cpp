/**
 * 10D. LCIS
 * 
 * 定义一个序列中删去部分元素得到的序列为原序列的子序列，求两组序列的最大升序子序列
 *
 * http://codeforces.com/contest/10/submission/7325338
 * http://blog.fly2best.com/algorithm/2013/05/11/longges-common-increasing-subsequence/
 */

#include <iostream>
using namespace std;

const int MAXN = 1000;

int A[MAXN], B[MAXN];
int P[MAXN]; // 公共序列前一位
int F[MAXN]; // 公共序列长度
int ret[MAXN];
int N, M;

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++ i) cin >> A[i];
    cin >> M;
    for (int i = 1; i <= M; ++ i) cin >> B[i];
    for (int i = 1; i <= N; ++ i) {
        int best = 0; // 存储较小的公共升序序列的尾部元素序号
        for (int j = 1; j <= M; ++ j) {
            if (A[i] == B[j] && F[best] + 1 > F[j]){
                F[j] = F[best] + 1;
                P[j] = best;
            } else if (B[j] < A[i] && F[j] > F[best]){
                // best存储了A[i]>B[j]中的B[j]的最大值
                best = j;
            }
            // cout<<F[j]<<"--"<<best<<"\t";
        }
        // cout<<endl;
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