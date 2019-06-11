/**
 * poj 2342
 *
 *
 */

#include <iostream>
#include <math.h>
using namespace std;

const int MAXN = 6001;

int dp[MAXN][2]; // 第i号人选择与不选得到的最大分值
int v[MAXN]; // 第i号人的value
int s[MAXN]; // 第i号人的supervisor
int N;

int solve(int n, int chose){
    int result = 0;
    for (int i = 0; i < N; ++i) {
        if(s[i] != n) continue;
        if(chose == 1){
            result = max(result, solve(i, 0));
        }else{
            result = max(result, solve(i, 1) + v[n]);
        }
    }
    dp[n][chose] = result;
    return result;
}

int main() {

    int t;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>v[i];
    }

    for (int j = 0; j < N; ++j) {
        cin>>t>>s[t];
    }

    int result = 0;
    for (int k = 0; k < N; ++k) {
        result = max(result, solve(k, 0));
        result = max(result, solve(k, 1));
    }
    cout<<result<<endl;
    return 0;
}
