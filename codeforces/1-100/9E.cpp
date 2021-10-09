/*
在一个无向图中添加若干边，使得所有端点都属于且仅属于一个环。类似于一笔画问题。
如果有多个方案，输出表示边的点对序列的最小值，以字符顺序排序

方法1：
检查图中是否有环、是否存在一点度数大于2、是否有自环和其他节点共存，有则返回NO
对于已有边找到两端端点，找匹配，始终用编号最小的端点连接最大的，连接之后删除端点

方法2：
采用并查集，并查集的每个集合都为单链的
对度小于2的点添加边，将并查集合并，如果合并结果不是唯一集合，则输出NO
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 52;

int e1[MAXN*MAXN], e2[MAXN*MAXN];
int fa[MAXN]; // 并查集
int degree[MAXN];
vector<pair<int,int> > ans;

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unionset(int x,int y){
    int p1 = find(x);
    int p2 = find(y);
    if(p1!=p2) fa[p2]=p1;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>e1[i]>>e2[i];
    }

    for(int i=1;i<=n;i++) fa[i]=i;

    for(int i=1;i<=m;i++){
        unionset(e1[i],e2[i]);
        degree[e1[i]]++;
        degree[e2[i]]++;
        if(degree[e1[i]]>2 || degree[e2[i]]>2){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(degree[i]<=1 && degree[j]<=1 && find(i)!=find(j)){
                // 每一个端点
                unionset(j,i);
                degree[i]++;
                degree[j]++;
                ans.push_back(make_pair(j,i));
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(degree[i]==2)continue;
        for(int j=1;j<i;j++){
            if(degree[j]==1){
                // 原始集合可能只差一条边就能形成环
                unionset(j,i);
                degree[i]++;
                degree[j]++;
                ans.push_back(make_pair(j,i));
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            ans.push_back(make_pair(i,i));
        }
    }

    int p=find(1);
    for(int i=2;i<=n;i++){
        if(find(i)!=p){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
