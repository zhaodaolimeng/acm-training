/*
一组配对括号中有一部分符号缺失了，使用'?'表示
缺失位置补充左括号或有括号的代价不同，求补充成匹配括号的最小代价

x是当前截止当前多余的左括号个数，y为当前总括号数
dp[x][y]为最小代价
dp[x][y] = min(dp[x+1][y-1],dp[x-1][y-1])
由于是逐行计算，所以可以将该过程压缩成为dp[x][2]
该方式的复杂度为O(n^2)

// const int maxn = 5*10000+1;
// int dp[maxn][2];

另一种方式是使用贪婪方法，可以做到O(nlogn)
考虑所有的'?'都先设置成为')'，任务转变为将一部分位置的括号')'转变为'('，且总代价最小
最小代价可使用优先队列维护，队列存放的key为')'转变为'('后代价的提升
从左向右遍历原始输入
*/

#include<bits/stdc++.h>
using namespace std;


priority_queue<pair<int,int> > Q;

int main(){

    string seq;
    long long cost=0,lc,rc,lb=0;

    cin>>seq;

    for(int i=0;i<seq.size();i++){
        if(seq[i]=='?') {
            cin>>lc>>rc;
            seq[i]=')';
            lb--;
            Q.push(make_pair(rc-lc,i));
            cost += rc;
        }
        else if(seq[i]=='(') lb++;
        else if(seq[i]==')') lb--;

        if(lb<0){
            if(Q.empty()){
                cout<<-1<<endl;
                return 0;
            }
            cost = cost - Q.top().first;
            seq[Q.top().second] = '(';
            lb += 2;
            Q.pop();
        }
    }
    if(lb > 0)
        cout<<-1<<endl;
    else {
        cout<<cost<<endl<<seq<<endl;
    }
    return 0;
}

