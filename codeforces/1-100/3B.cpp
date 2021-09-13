/*
n只两类小船ab，a体积为1，b体积为2，每条船容量给定
现在要把所有船都放在体积为v卡车中，所有船容量之和尽可能大
*/

#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn = 100010;
int n,v,t,p,tot_cap=0;
struct Boat{
    int num;
    int type;
    int cap;
    bool operator < (const Boat & other) const{
        return cap*other.type < other.cap*type;
    }
};
 
int main(){
 
    cin>>n>>v;
    vector<Boat> boats(n);
    for(int i=0;i<n;i++) {
        boats[i].num = i+1;
        cin>>boats[i].type>>boats[i].cap;
    }
    sort(boats.begin(),boats.end());
 
    // for(int i=0;i<n;i++){
    //     cout<<boats[i].num<<" "<<boats[i].type<<" "<<boats[i].cap<<endl;
    // }
 
    vector<int> ret;
 
    int last_t1=n;
    for(p=n-1;p>=0 && v>=boats[p].type;p--){    
        tot_cap+=boats[p].cap;
        ret.push_back(boats[p].num);
        v-=boats[p].type;
        if(boats[p].type==1)last_t1=p;
    }
 
    // 如果还剩余一个空间，则检查序列中的一个type=1的位置改成type=2后是否能带来tot_cap的提升
    if(v==1&&p>=0&&last_t1!=n){
        for(;p>=0;p--){
            if(boats[p].type==2){
                if(boats[last_t1].cap<boats[p].cap){
                    ret[n-1-last_t1] = boats[p].num;
                    tot_cap += boats[p].cap - boats[last_t1].cap;
                }
                break;
            }
        }
    }

    cout<<tot_cap<<endl;
    if(ret.size()>0){
        cout<<ret[0];
        for(int i=1;i<ret.size();i++) cout<<" "<<ret[i];    
    }
    cout<<endl;
    return 0;
}
