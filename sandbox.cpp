#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t;
    std::cin>>n;
    vector<int>ret;

    while(1){
        t = n%9;
        n = n/9;
        ret.push_back(t);
    }
    


    return 0;
}