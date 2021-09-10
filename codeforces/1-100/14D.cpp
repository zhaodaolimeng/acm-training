#include<bits/stdc++.h>

using namespace std;

const int MAX = 210;
int n,best_depth,best_path;
int u[MAX],v[MAX];
vector<int> tree[MAX];

/*
在一个树结构中找到两个不相邻的路径，使得这两个路径长度的乘积最大
以递归方式计算每个节点的最大深度
之后计算以每个节点为分离点时子图中最大路径的乘积
*/

int dfs(int cur, int pre, int depth){
    int best_depth = depth;
    for(int i=0;i<tree[cur].size();i++){
        if(tree[cur][i] == pre) continue;
        int t = dfs(tree[cur][i],cur,depth+1);
        best_path = max(best_path,best_depth+t-2*depth);
        best_depth = max(best_depth,t);
    }
    return best_depth;
}

int main(){
    //
    int a,b,ret=0;
    cin>>n;
    for(int i=0; i<n-1; i++) {
        cin>>u[i]>>v[i];
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
    }
    for(int i=0; i<n; i++){

        best_path = 0;
        dfs(u[i],v[i],1);
        int best_path_left = best_path;

        best_path = 0;
        dfs(v[i],u[i],1);
        ret = max(ret, best_path*best_path_left);
    }
    cout<<ret<<endl;
    return 0;
}