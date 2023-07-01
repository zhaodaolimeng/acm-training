#include<bits/stdc++.h>

using namespace std;

int main(){
    string in,ret;
    std::cin>>in;

    bool is_root = true;

    for(int i=0;i<in.size();){
        if(in[i]=='/'){
            while(i<in.size() && in[i]=='/') i++;
            if(i < in.size() || (i == in.size() && is_root))
                ret += '/';
        }else{
            ret += in[i];
            is_root = false;
            i++;
        }
    }

    std::cout<<ret<<endl;

    return 0;
}