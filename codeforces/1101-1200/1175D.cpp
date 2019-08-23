#include <bits/stdc++.h>

using namespace std;

/**
 * 参考了http://codeforces.com/contest/1175/submission/55166348
 * |.........[--|
 * |......[-----|
 * |..[---------|
 * |.[----------|
 * 公式有递推的特性
 */

const int MAXN = 300005;
long long s[MAXN];

int main(){
    long long n, k, a, ret = 0;
    cin>>n>>k;
    s[0] = 0;
    for(int i=1; i<=n; i++) {
        cin>>a;
        s[i] = s[i-1] + a;
    }
    sort(s+1, s+n);  // 注意这里，最后一位必选
    for(int i=1; i<k; i++)
        ret -= s[i];
    ret += k*s[n];
    cout<<ret<<endl;
    return 0;
}
