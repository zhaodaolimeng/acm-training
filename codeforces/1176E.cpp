#include <set>
#include <vector>
#include <iostream>

using namespace std;

// 从任意节点开始
// 如果相邻没有选中，则选中该点
// 如果最终选中点数大于n/2，则输出反选结果

int main(){

    const int MAX_N = 200010;

    int T, m, n, a, b;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<set<int>> adj(n, set<int>());
        vector<bool> chosed(n, false);
        vector<bool> vis(n, false);

        for(int i=0; i<m; i++){
            cin>>a>>b;
            adj[a-1].insert(b-1);
            adj[b-1].insert(a-1);
        }

        // cout<<"==="<<endl;

        int ret = 1;
        chosed[0] = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!chosed[j] && !vis[j]){
                    bool is_chosed = false;
                    for(int k : adj[j]){
                        if(chosed[k]){
                            is_chosed = true;
                            break;
                        }
                    }
                    if(is_chosed){
                        vis[j] = true;
                    }else{
                        for(int k : adj[j]){
                            if(!vis[k]){
                                chosed[k] = true;
                                ret ++;
                                break;
                            }
                        }
                    }
                }
            }
            // for(int t : chosed) cout<<t<<"\t";
            // cout<<endl;
        }

        // cout<<"---"<<endl;
        // for(int i : vis) cout<<i<<"\t";
        // cout<<endl;

        // cout<<"+++"<<endl;
        // cout<<ret<<endl;

        if(ret > n/2){
            ret = n - ret;
            for(int i=0; i<n; i++) chosed[i] = !chosed[i];
        }
        cout<<ret<<endl;
        for(int i=0; i<n; i++) if(chosed[i]) cout<<i+1<<" ";
        cout<<endl;
    }
    return 0;
}

