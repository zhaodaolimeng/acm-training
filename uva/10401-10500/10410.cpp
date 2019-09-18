#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;
// using namespace std::this_thread;
// using namespace std::chrono;


int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n_str, t;
    vector<int> bfs, dfs;
    vector<vector<int>> h_tree;
    map<int, vector<int>> children_map;
    
    while(cin>>n_str && n_str != 0){

        bfs.clear();
        dfs.clear();
        h_tree.clear();
        children_map.clear();

        for(int i=0; i<n_str; i++){
            cin>>t;
            bfs.push_back(t);
            children_map[t] = vector<int>();
        }
        for(int i=0; i<n_str; i++){
            cin>>t;
            dfs.push_back(t);
        }

        int pbfs = 1, pdfs = 0;
        vector<int> r;
        r.push_back(bfs[0]);
        h_tree.push_back(r);
        h_tree.push_back(vector<int>());

        while(pbfs < bfs.size()){
            while(pdfs < dfs.size() && dfs[pdfs] != bfs[pbfs])
                pdfs ++;
            if(pdfs == dfs.size()){
                pdfs = 0;
                vector<int> r;
                h_tree.push_back(r);
                continue;
            }
            h_tree.back().push_back(bfs[pbfs]);
            pbfs++;
        }

        // cout<<"depth: "<<endl;
        // for(auto const & pl : h_tree) {
        //     for(auto const & p : pl) cout<<" "<<p;
        //     cout<<endl;
        // }
        // cout<<"====="<<endl;
        
        for(int i=0; i<h_tree.size()-1; i++){
            int p1 = 0, p2 = 0, p3 = 0;
            for(p1 = 0; p1 < h_tree[i].size()-1; p1++){
                int bro = p1 + 1;
                
                for(; p2 < h_tree[i+1].size(); p2++){
                    bool search_end = false;
                    for(; p3 < dfs.size(); p3++) {
                        // cout<<p1<<" "<<p2<<" "<<p3<<endl;
                        if(dfs[p3] == h_tree[i][bro]){
                            search_end = true;
                            break;
                        }
                        if(dfs[p3] == h_tree[i+1][p2]){
                            children_map[h_tree[i][p1]].push_back(h_tree[i+1][p2]);
                            break;
                        }
                    }
                    if(search_end) break;
                }
            }
            for(; p2 < h_tree[i+1].size(); p2++){
                for(; p3 < dfs.size(); p3++) {
                    // cout<<p1<<" "<<p2<<" "<<p3<<endl;
                    if(dfs[p3] == h_tree[i+1][p2]){
                        children_map[h_tree[i][p1]].push_back(h_tree[i+1][p2]);
                        break;
                    }
                }
            }

            // for(auto const & e : children_map){
            //     cout<<e.first<<":";
            //     for(int i=0; i<e.second.size(); i++) cout<<" "<<e.second[i];
            //     cout<<endl;
            // }
            // cout<<"-----"<<endl;
        }

        for(auto const & e : children_map){
            cout<<e.first<<":";
            for(int i=0; i<e.second.size(); i++) cout<<" "<<e.second[i];
            cout<<endl;
        }

    }

    
}

/*
8
4 3 5 1 2 8 7 6
4 3 1 7 2 6 5 8
*/