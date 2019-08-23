#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

int main(){    
    
    string str;
    vector<string> vs;
    int cnt=0, t, left, right, tick=0;
    
    while(getline(cin, str)){        
        vs.push_back(str);
        cnt = max(cnt, (int)str.length());
    }    
    for(int i=0; i<cnt+2; i++) cout<<"*";
    cout<<endl;        
    for(int i=0; i<vs.size(); i++){
        cout<<"*";
        t = (cnt-vs[i].length());
        if(t%2==0){
            left = t/2;
            right = t/2;
        }else{
            if(tick==0){
                left = t/2;
                right = t/2+1;                
                tick = 1;
            }else{
                right = t/2;
                left = t/2+1;
                tick = 0;
            }
        }
        for(int j=0; j<left; j++) cout<<" ";
        cout<<vs[i];
        for(int j=0; j<right; j++) cout<<" ";
        cout<<"*"<<endl;
    }    
    for(int i=0; i<cnt+2; i++) cout<<"*";
    cout<<endl;    
    return 0;
}
