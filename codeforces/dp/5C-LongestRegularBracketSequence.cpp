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

const int MAXLEN = 1000100;
int dp[MAXLEN] = {0};

int main(){
    
    int count = 0, ret=0, k;
    stack<int> st;
    string str;
    cin>>str;    
    
    for(int i=0;i<str.size();i++){              
        if(str[i]=='('){
            st.push(i);
            continue;
        }
        if(!st.empty()){
            k = st.top();
            st.pop();
            
            dp[i] = (k==0?0:dp[k-1]) + (i-k+1);
            if(dp[i]>ret){
                count=1;
                ret=dp[i];
            }else if(dp[i]==ret){
                count++;
            }
        }
    }
    if(ret == 0)
        cout<<"0 1"<<endl;
    else
        cout<<ret<<" "<<count<<endl;
    //system("PAUSE");
    return 0;
}
