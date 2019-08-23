#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, depth = 0;
    string s, ret;
    
    
    cin>>n>>s;

    for(char c : s){
        if(c == '('){
            ret.push_back('0' + depth % 2);
            depth ++;
        }else{
            depth --;
            ret.push_back('0' + depth % 2);
        }
    }
    cout<<ret<<endl;
    return 0;
}