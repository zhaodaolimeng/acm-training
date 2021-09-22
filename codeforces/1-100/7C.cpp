/*
方程Ax+By+C=0是否有整数解
可使用扩展欧几里得定理求解
扩展欧几里得定理指方程Ax+By=gcd(A,B)一定有整数解
*/

#include<bits/stdc++.h>
using namespace std;

void exgcd(long long a, long long b, long long& d, long long& x, long long& y){
    if(b==0){
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a%b, d, y, x);
        y -= x*(a/b);
    }
}

int main(){
    long long A,B,C,D=0,x=0,y=0;
    // cout<<-10%3<<endl; // -1
    // cout<<-10/3<<endl; // -3

    cin>>A>>B>>C;
    // if(A%C==0&&B%C==0){
    //     A /= C;
    //     B /= C;
    //     while(abs(A)>0 && abs(B)>0){
    //         if(abs(A)>abs(B)) {
    //             A %= B;
    //             x += A/B;
    //         } else {
    //             B %= A;
    //             y += B/A;
    //         }
    //     }
    //     cout<<endl;
    // } else {
    //     cout<<-1<<endl;
    // }
    exgcd(A,B,D,x,y);
    if(C%D!=0) cout<<-1<<endl;
    else cout<<-x*C/D<<" "<<-y*C/D<<endl;
    return 0;
}
