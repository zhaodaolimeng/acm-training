#include <vector>
#include <iostream>

using namespace std;

int main(){
    int l;
    cin>>l;

    vector<long long> st;
    string cmd;
    bool overflow = false;
    long long param, ret = 0, bound = (1LL<<32) - 1;

    st.push_back(1);

    for(int i=0; i<l; i++){
        cin>>cmd;
        if(cmd == "add"){
            ret += st.back();
            if(st.back() == -1 || ret > bound) overflow = true; 
        }else if(cmd == "for"){
            cin>>param;
            if(param * st.back() > bound || st.back() == -1)
                st.push_back(-1);
            else
                st.push_back(st.back() * param);
        }else if(cmd == "end"){
            st.pop_back();
        }
    }
    if(overflow){
        cout<<"OVERFLOW!!!"<<endl;
    }else{
        cout<<ret<<endl;
    }
}
