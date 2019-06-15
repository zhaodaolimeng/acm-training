#include <iostream>
#include <vector>
#include <queue>
#include <map>

/**
 * 拓扑排序最后得到的点一定是一个候选点
 * 但如果拓扑排序最后得到的是一个链的话，候选点需要在这个链中的节点中确定
 * 完全参考了mnbvmar的答案：http://codeforces.com/contest/1182/submission/55453083
 */

using namespace std;

const int N = 100010;

int n;
int dist[N], cur_deg[N];
vector<int> adj[N];

void dfs_dist(int cur, int parent){
    // 计算每个节点到cand的距离；cur为当前节点，parent为父节点；输出改写后的dist值
    for(int s : adj[cur]){
        if(s == parent) continue;
        dist[s] = dist[cur] + 1;
        dfs_dist(s, cur);
    }
}

void check_root(int cand){
    // 检查候选点，满足条件直接输出后终止程序
    fill_n(dist, n, 0);
    fill_n(cur_deg, n+1, 0);
    dfs_dist(cand, -1);

    for(int i=0; i<n; i++){
        int d = dist[i];
        if(cur_deg[d] && cur_deg[d] != adj[i].size())
            return ;
        cur_deg[d] = adj[i].size();
    }
    cout<<cand+1<<endl;
    exit(0);
}

int main(){
    int v, u;
    cin>>n;
    if(n == 1) {
        cout<<1<<endl;
        return 0;
    }

    for(int i=0; i<n-1; i++){
        cin>>v>>u;
        v--, u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> degs(n);    // 每个节点的度
    queue<int> leaf_queue;  // 用于拓扑排序
    for(int i=0; i<n; i++){
        degs[i] = adj[i].size();
        if(degs[i] == 1) leaf_queue.push(i);
    }

    vector<int> order;    // 拓扑遍历的顺序，从叶节点到根节点
    while(!leaf_queue.empty()){
        int v = leaf_queue.front(); leaf_queue.pop();
        order.push_back(v);
        for(int s : adj[v]){
            if((--degs[s]) == 1)
                leaf_queue.push(s);
        }
    }

    int cand = order.back();
    check_root(cand);

    map<int, int> nxt_cands;  // 节点的深度与节点号
    for(int s : adj[cand]){
        int cur = s, pnt = cand, depth = 1;
        bool ok = true;
        while(true){
            if(adj[cur].size() == 1) break;  // 仍然是一个链上
            if(adj[cur].size() > 2) {
                ok = false;
                break;
            }
            int nxt = adj[cur][0] + adj[cur][1] - pnt; // 得到链的另一端
            ++ depth;
            pnt = cur;
            cur = nxt;
        }
        if(ok) nxt_cands[depth] = cur;
    }

    int num_proc = 0;
    for(auto &info : nxt_cands){
        if(num_proc > 2) continue;
        check_root(info.second);
        num_proc ++;
    }
    cout<<-1<<endl;
}
