#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;


int main(int argc, char**args){

    int mem[101];
    int t, m;
    string cmd;
    int param;

    while(cin>>t>>m){
        memset(mem, 0, sizeof(mem));
        int idx = 1;
        for(int i=0;i<t;i++){
            cin>>cmd;
            if(cmd == "alloc"){
                cin>>param;
                bool find = false;
                for(int j=0; j<=m-param; j++){
                    if(mem[j]==0){
                        int k = j;
                        for(; mem[k]==0 && k-j<param; k++);
                        if(k-j == param){
                            for(int flag = j; flag<k; flag++) mem[flag] = idx;
                            idx ++;
                            find = true;
                            break;
                        }else
                            j = k;
                    }
                }
                if(!find) cout<<"NULL"<<endl;
                else cout<<idx-1<<endl;
            }else if(cmd == "erase"){
                cin>>param;
                if(param == 0)
                    cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
                else{
                    bool find = false;
                    for(int j=0; j<m; j++){
                        if(find && mem[j]!= param) break;
                        if(mem[j] == param){
                            find = true;
                            mem[j] = 0;
                        }
                    }
                    if(!find) cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
                }
            }else{
                int p = 0;
                while(p < m){
                    while(mem[p]!=0 && p<m)p++;
                    if(p==m)break;
                    if(p != m){
                        int q = p+1;
                        while(mem[q]==0 && q<m)q++;
                        if(q!=m){
                            while(mem[q]!=0 && q<m){
                                mem[p] = mem[q];
                                mem[q] = 0;
                                p++;
                                q++;
                            }
                        } else
                            p = q;
                    }
                }
            }
        }
    }

}