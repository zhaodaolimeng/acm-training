#include <bits/stdc++.h>

using namespace std;

/*
每次可选择一个序列中的若干个元素进行减半操作
问最终得到至少k个相同元素需要多少步操作

该问题第一时间考虑是排序之后找到一个k大小的滑窗进行检查，但实际上这种方式是会遗漏的
问题本质上适合于使用暴力枚举的方式求解
一种思路是记录所有出现的前缀，以及前缀后还有多少位
*/

map<int, vector<int>> mv;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n,k,t,ans = INT_MAX;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>t;
        for(int j=0; t!=0; j++,t>>=1){
            mv[t].push_back(j);
        }
    }

    // for(auto& p : mv){
    //     cout<<p.first<<":"<<endl;
    //     for(auto & pi : p.second) {
    //         cout<<pi<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for(auto& p : mv){
        if(p.second.size() >= k){
            sort(p.second.begin(),p.second.end());
            t = 0;
            for(int i=0;i<k;i++) t += p.second[i];
            ans = min(ans, t);
        }
    }

    cout<<ans<<endl;
}
