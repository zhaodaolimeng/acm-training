/**
 * codeforces 988D
 * ==============
 * 原方法枚举每个点对之后进行二分搜索找中间点，但超时。
 * ac答案使用set进行存储进行快速判断。
 */
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <set>
using namespace std;

set<int> vset;

int main(){

    int n, t;
    cin>>n;

    for(int i = 0; i < n; i ++) {
        cin>>t;
        vset.insert(t);
    }

    for(int i : vset){
        for(int j = 0; j < 31; j++){
            t = (1<<j);
            if(vset.count(i - t) && vset.count(i + t))
                return !(cout<<3<<endl<<i-t<<" "<<i<<" "<<i+t<<endl);
        }
    }

    for(int i : vset){
        for(int j = 0; j < 31; j++){
            t = (1<<j);
            if(vset.count(i - t))
                return !(cout<<2<<endl<<i-t<<" "<<i<<endl);
        }
    }
    return !(cout<<1<<endl<<*vset.begin()<<endl);
}

// int seq[200010];

// bool is_power_of_two(int num){
//     if(num == 1) return false;
//     while(num > 1){
//         if((num & 1) != 0) return false;
//         num>>=1;
//     }
//     return true;
// }

// int main() {

//     int n, t;
//     int v1, v2, v3;
//     bool found2 = false, found3 = false;
//     cin>>n;

//     for(int i = 0; i < n; i ++) cin>>seq[i];
//     sort(seq, seq + n);

//     for(int i = 0; i < n; i ++){
//         for(int j = i + 1; j < n; j++){            
//             if(!found3 && is_power_of_two(abs(seq[j] - seq[i]))){
//                 v1 = seq[i], v2 = seq[j];
//                 found2 = true;
//                 t = (v1 + v2) / 2;
//                 if(binary_search(seq, seq + n, t) && abs(t - v1) > 1){
//                     v3 = t;
//                     found3 = true;
//                 }
//             }
//             if(found3) break;
//         }
//         if(found3) break;
//     }
    
//     if(found3){
//         cout<<3<<endl;
//         cout<<v1<<" "<<v2<<" "<<v3<<endl;
//     } else if(found2) {
//         cout<<2<<endl;
//         cout<<v1<<" "<<v2<<endl;
//     } else {
//         cout<<1<<endl;
//         cout<<seq[0]<<endl;
//     }
//     return 0;
// }
