#include<bits/stdc++.h>
using namespace std;


char M[3][3];

int main(){
 
    int xs=0,os=0,xwin=0,owin=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            cin>>M[i][j];
            if(M[i][j] == '0')os ++;
            else if(M[i][j] == 'X') xs ++;
        }
    
    for(int i=0;i<3;i++){
        if(M[i][0] == M[i][1] && M[i][1] == M[i][2] && M[i][0]!='.'){
            if(M[i][0]=='X') xwin++; else owin++;
        }
        if(M[0][i] == M[1][i] && M[1][i] == M[2][i] && M[0][i]!='.'){
            if(M[0][i]=='X') xwin++; else owin++;
        }
    }
    if(M[0][0] == M[1][1] && M[1][1] == M[2][2] && M[0][0]!='.') {
        if(M[1][1]=='X') xwin++; else owin++;
    }   
    if(M[2][0] == M[1][1] && M[1][1] == M[0][2] && M[0][2]!='.'){
        if(M[1][1]=='X') xwin++; else owin++;
    }

    if(os>xs||xs-os>1||(owin>0&&xwin>0)||(owin>0&&xs>os)||(xwin>0&&xs==os)){
        cout<<"illegal"<<endl;
    }else if (xwin + owin >= 1){
        if(xwin > 0) cout<<"the first player won"<<endl;
        else cout<<"the second player won"<<endl;
    }else if(xwin+owin == 0){
        if(os + xs == 9) cout<<"draw"<<endl;
        else if(os == xs) cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }   
    return 0;
}

/*
X0X
X0.
X0.

XXX
0X0
00X

000
X.X
X.X

X00
0XX
XX0
*/