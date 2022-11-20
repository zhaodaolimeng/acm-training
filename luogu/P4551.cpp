#include<bits/stdc++.h>

using namespace std;

// 树结构上找到异或和最大的路径
// 以任意节点为根，遍历每个节点
// 在遍历的同时，将节点异或值存入Trie树，并在树上查询和当前节点异或最大的值

int pnext[200001][2];
int last = 0;


void insert(int val){
    int c,p=0;
    for(int i=0;i<31;i++){
        c = (val&(1<<31))>>30;
        val <<= 1;
        if(pnext[p][c]!=-1)
            p = pnext[p][c];
        else{
            p ++;
            pnext[p][c] = p;
        }
    }
}

int search(int val){
    int p=0,c,res=0;
    for(int i=0;i<31;i++){
        c = (val&(1<<31))>>30;
        if(pnext[p][1-c]==-1)
            p = pnext[p][c];
        else
            p = pnext[p][1-c];
        res += (res<<1)&c;
    }
    return res;
}

int main(){

    vector<vector<int> > connect(100001);
    vector<bool> vis(100001);
    map<pair<int,int>,int> weight;
    stack<int> st;

    int node_cnt,a,b,w,path,t,max_xor=0;
    cin>>node_cnt;
    while(cin>>a>>b>>w){
        connect[a].push_back(b);
        connect[b].push_back(a);
        weight[make_pair(a,b)] = w;
        weight[make_pair(b,a)] = w;
    }
    
    // dfs
    path = 0;
    st.push(1);
    while(!st.empty()){
        a = st.top();st.pop();
        vis[a] = 1;
        for(int i=0;i<connect[a].size();i++){
            b = connect[a][i];
            if(vis[b] != 1){
                st.push(b);
                path ^= weight[make_pair(a,b)];
                max_xor = max(search(path), max_xor);
                insert(path);
            }
        }
    }
    cout<<max_xor<<endl;
    return 0;
}

/*
4
1 2 3
2 3 4
2 4 6
*/
