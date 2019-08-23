/**
 * 10D. LCIS
 *
 * 这个答案非常好，但是也很绕：
 * http://codeforces.com/contest/10/submission/7325338
 * http://blog.fly2best.com/algorithm/2013/05/11/longges-common-increasing-subsequence/
 */

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