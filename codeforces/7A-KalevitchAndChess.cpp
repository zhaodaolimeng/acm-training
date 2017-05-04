#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

char board[8][8];

int main(){
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>board[i][j];
        }
    }

    int cnt = 0;
    for(int i=0;i<8;i++){
        
        bool all_black = true;
        for(int j=0; j<8; j++)
            if(board[i][j]=='W') {
                all_black = false;            
                break;
            }
        if(all_black) cnt ++;
        
        all_black = true;
        for(int j=0; j<8; j++)
            if(board[j][i]=='W') {
                all_black = false;        
                break;
            }
        if(all_black) cnt ++;
    }
    if(cnt==16)
        cnt = 8;
    cout<<cnt<<endl;    
}
