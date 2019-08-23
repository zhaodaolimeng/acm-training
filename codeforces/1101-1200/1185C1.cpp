#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    int n, M, t;

    cin>>n>>M;

    multiset<int> order;
    vector<int> ret;

    int pM = M;

    for(int i=0; i<n; i++){
        cin>>t;
        int res = pM, cnt = 0;
        if(t <= res){
            ret.push_back(0);
        }else{
            for (multiset<int>::reverse_iterator rit=order.rbegin(); rit!=order.rend(); ++rit){
                res += *rit;
                cnt++;
                if(t <= res){
                    ret.push_back(cnt);
                    break;
                }
            }
        }
        pM -= t;
        order.insert(t);
    }

    for(int i=0; i<n; i++) cout<<ret[i]<<" ";
    cout<<endl;
    return 0;
}
