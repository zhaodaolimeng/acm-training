/*
 * http://blog.csdn.net/maxichu/article/details/47763399
 * 题目大意：
 * 在一个整数序列中找到一组等长子序列，这组子序列需要满足
 * (1) 子序列序列尽可能长
 * (2) 子序列中不同的设备的高度的差值不能大于k
 * 
 * 解题思路：
 * 可使用一次遍历扫描设备序列，因为如果有一种方式可扫描出最长的子序列组，
 * 那么要发现更长的子序列肯定不需要重复之前肯定不需要重复扫描之前的组
 * 可使用两个单调序列存储当前的扫描状态，使用递减序列存储上界，递增序列存储下界
 * 当这两个队列的头的差值超过k时，说明已经捕获了最长的子序列组
 * 通过序列出队还原这组子序列
 * 
 * 其余的单调队列题目：91B、251A、372C
*/
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

const int MAXN = 1e5 + 10;
int book[MAXN];
vector<pair<int, int> > p; // 用于还原序列
deque<int> high; // 存最大值，顺序为从高到低的
deque<int> low;  // 存最小值，顺序为从低到高的

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,k;
    while(cin>>n>>k){
        for(int i = 1; i < 1 + n; i++)
            scanf("%d",&book[i]); 
        
        p.clear();
        high.clear();
        low.clear();
        
        int i, j;
        int a, b; //a为最大书数量，b为序列数量
        
        for(i=j=1; i<n+1; i++){
            
            while(!high.empty() && high.back()<book[i]) high.pop_back();
            high.push_back(book[i]);            
            while(!low.empty() && low.back()>book[i]) low.pop_back();
            low.push_back(book[i]);
            
            while(!high.empty() && !low.empty() && high.front() - low.front() > k){ 
                // 队列中最后一个内容已经超出了限制，需要剔除
                if(p.empty() || i-j>a){
                    // 发现了更长的序列
                    p.clear();
                    b=1;
                    a=i-j;
                    p.push_back(make_pair(j, i-1));
                }else if(!p.empty() && i-j==a){
                    b++;
                    p.push_back(make_pair(j, i-1));
                }
                if(high.front()==book[j]) high.pop_front();
                if(low.front()==book[j]) low.pop_front();
                // 弹出经过的队首元素
                j++;
            }
        }
        
        while(j <= n){ 
            // 队列中最后一个内容已经超出了限制，需要剔除
            if(p.empty() || i-j>a){
                // 发现了更长的序列
                p.clear();
                b=1;
                a=i-j;
                p.push_back(make_pair(j, i-1));
            }else if(!p.empty() && i-j==a){
                b++;
                p.push_back(make_pair(j, i-1));
            }
            if(high.front()==book[j]) high.pop_front();
            if(low.front()==book[j]) low.pop_front();
            // 弹出经过的队首元素
            j++;
        }
        
        cout<<a<<" "<<b<<endl;
        for(int i=0; i<p.size(); i++)
            cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    
    return 0;
}

