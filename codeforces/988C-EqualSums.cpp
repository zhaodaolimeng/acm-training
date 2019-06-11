/**
 * codeforces 988C
 * ==============
 */
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

int k, n, sum, t;
int seq[200010];

int main() {

    // 使用hashmap存储“数值 - 位置对”，每次检查是否有数值想通
    map<int, pair<int, int> > value_pos;
    bool found = false;
    int result_i, result_j, another_i, another_j;

    cin>>k;
    for(int i = 0; i < k; i ++){
        cin>>n;
        sum = 0;
        for(int j = 0; j < n; j++){
            cin>>seq[j];
            sum += seq[j];
        }
        if(!found){
            for(int j = 0; j < n; j++){
                t = sum - seq[j];
                if(value_pos.find(t) == value_pos.end()){
                    value_pos[t] = make_pair(i, j);
                } else if(value_pos[t].first != i){
                    found = true;
                    result_i = i, result_j = j;
                    another_i = value_pos[t].first;
                    another_j = value_pos[t].second;
                }
            }
        }
    }

    if(found){
        cout<<"YES"<<endl;
        cout<<another_i + 1<<" "<<another_j + 1<<endl;
        cout<<result_i + 1<<" "<<result_j + 1<<endl;
    } else {
        cout<<"NO"<<endl;
    }    
    return 0;
}
