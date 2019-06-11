// poj 3069

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int R, n, t;
    while(cin>>R>>n){

        vector<int> army;
        vector<int> army_new;

        if(R==-1 && n==-1)break;

        for(int i=0;i<n;i++){
            cin>>t;
            army.push_back(t);
        }

        sort(army.begin(), army.end());
        army_new.push_back(army[0]);
        for(int i=1;i<n;i++)
            if(army[i] != army[i-1])
                army_new.push_back(army[i]);

        int result = 0, flag = 0, last;
        n = (int)army_new.size();
        while(flag < n){
            last = army_new[flag];
            while(flag < n && army_new[flag] - last <= R) flag++;
            t = army_new[flag-1];
            while(flag < n && army_new[flag] - t <= R) flag++;

            result ++;
        }
        cout<<result<<endl;
    }

    return 0;
}

/*
0 3
10 20 20
10 7
70 30 1 7 15 20 50
-1 -1
 */