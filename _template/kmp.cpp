#include<bits/stdc++.h>

using namespace std;

int main(){

    string ps = "abc#abababcab";
    vector<int> prefix(ps.length());

    for(int i=1;i<ps.size();i++){
        int p = prefix[i-1];
        while(p>0 && ps[i]!=ps[p]) p = prefix[p-1];
        if(ps[i] == ps[p]) p+=1;
        prefix[i] = p;
    }
    return 0;
}
