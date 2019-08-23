#include <bits/stdc++.h>

using namespace std;

string postorder(string pre_order, string in_order){
    if(pre_order.size() == 1 || pre_order.size() == 0)
        return pre_order;
    char mid = pre_order[0];
    int mid_idx = 0;
    for(int i=0; i<in_order.size(); i++){
        if(mid == in_order[i]){
            mid_idx = i;
            break;
        }
    }
    string s_left="", s_right="";
    s_left = postorder(pre_order.substr(1, mid_idx), in_order.substr(0, mid_idx));
    s_right = postorder(
        pre_order.substr(mid_idx+1, pre_order.size()-1-mid_idx),
        in_order.substr(mid_idx+1, pre_order.size()-1-mid_idx));
    return s_left + s_right + mid;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string pre_order, in_order;
    while(cin>>pre_order){
        cin>>in_order;
        cout<<postorder(pre_order, in_order)<<endl;
    }
}

// DBACEGF ABCDEFG ACBFGED
// BCAD CBAD CDAB