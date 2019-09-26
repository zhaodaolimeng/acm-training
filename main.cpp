#include <bits/stdc++.h>

using namespace std;


int main(){

    vector<int> va[2];
    va[0].push_back(10);
    va[0].push_back(10);
    va[0].push_back(10);
    va[1].push_back(10);
    va[1].push_back(10);
    va[1].push_back(10);
    

    for(int i=0; i<2; i++){
        for(int j=0; j<va[i].size(); j++) cout<<va[i][j]<<" ";
        cout<<endl;
    }


    return 0;
}

