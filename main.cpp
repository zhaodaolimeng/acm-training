/**
 * codeforces 17B 最小生成树
 * ==============
 */
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_INT (1<<31)-1

int n, m;
int cost[1001][1001];
int q[1001];

map<int, vector<int> > G;
vector<int> S;

int prim(){
    int total = 0;
    S.push_back(0);
    
    for(int edge=0; edge<n-1; edge++){
        // 检查与已访问过的节点有邻接关系的边
        int min_cost = MAX_INT, min_cost_node;
        for(int i=0; i<S.size(); i++){
            for(auto const & t : G[S[i]]){

                if(cost[])

            }
        }
        // 找到最小边，加入结果集合
        
    }
    return total;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>q[i];

    cin>>m;
    int a, b, c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        cost[a][b] = c;
        if(!G.count(a)){
            vector<int> v;
            v.push_back(b);
            G[a] = v;
        }else{
            G[a].push_back(b);
        }
    }

    cout<<prim()<<endl;

    return 0;
}

