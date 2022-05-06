/**
 * 10E. Greedy Change
 * 给定n种硬币，每种硬币有无穷多个，计划使用贪心方法得到目标金额M
 * 如果M无法通过贪心方法获得，则直接返回-1
 * 如果M无法通过贪心方法获得最优解，则返回M中的最小值
 * 
 * 1 3 4 -> 6  3+3=6 4+1+1=6
 * 
 * 注意到最后一个数字一定是1，那么两重循环枚举a,b两个值
 * 当存在一个数target = ((a+b)/b)*b且(a+b)/b < target%a + target/a时，
 * 无法用贪心方法求解，此时返回target
 * 
 * FIXME
 * 
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 410;

int a[MAXN];

int main(){
    int n, ret=-1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        for(int j=i+1; j<n; j++){
            int target = ((a[i]+a[j])/a[j]);
            int tot=(target*a[j])/a[i],t=(target*a[j])%a[i];
            for(int k=j;k<n;k++){
                // 找到target*%a[i]使用的最新少的更小面额硬币数量
                if(t>=a[k]) {
                    tot+=t/a[k];
                    t-= (t/a[k])*a[k];
                }
            }
            if(target < tot){
                // cout<<"i="<<i<<"\tj="<<j<<"\t"<<target<<"\t"<<(target*a[j])%a[i]<<"\t"<<(target*a[j])/a[i]<<endl;
                ret = target*a[j];
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}
/*
4
17 8 7 1

5
9 8 5 2 1
// 13
*/