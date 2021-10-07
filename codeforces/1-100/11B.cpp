/*
使用1...n个连续整数加或减得到给定整数x，问n的最小值

分析20以内的用例可以发现规律
对于任意x，总能构造一个略大于x的y=n*(n+1)/2
之后可从1...n之间的数字中找到一个数字t变更为-t
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y=0,cnt=0;
    cin>>x;
    x = abs(x);
    
    while(x>y || (y-x)%2 == 1){
        cnt++;
        y+=cnt;
    }
    cout<<cnt<<endl;
    return 0;
}
