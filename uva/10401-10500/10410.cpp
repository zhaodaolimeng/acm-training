#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

map<int, vector<int>> children_map;

void search(deque<int>&bfs, deque<int>&dfs){
    int parent = bfs.front(); bfs.pop_front(); dfs.pop_front();

    sleep_until(system_clock::now() + milliseconds(100));

    while(bfs.size() > 0){

        deque<int> left_dfs, left_bfs;
        set<int> nodes;

        cout<<"------"<<endl;
        cout<<"bfs :";
        for(auto const & p : bfs) cout<<" "<<p;
        cout<<endl;

        int left_root = bfs.front();
        bfs.pop_front(); dfs.pop_front();
        if(children_map.find(parent) == children_map.end())
            children_map[parent] = vector<int>();
        children_map[parent].push_back(left_root);

        if(bfs.size() == 0) break;
        else if(bfs.size() == 1){
            left_dfs.push_back(left_root);
            left_dfs.push_back(dfs.front()); dfs.pop_front();
            left_bfs.push_back(left_root);
            left_bfs.push_back(bfs.front()); bfs.pop_front();
        }else {
            int brother = bfs.front(); bfs.pop_front();
            left_dfs.push_back(left_root);

            while(dfs.front() != brother) {
                left_dfs.push_back(dfs.front());
                nodes.insert(dfs.front());
                dfs.pop_front();
            }

            int bfs_size = bfs.size();
            bfs.push_back(brother);

            left_bfs.push_back(left_root);
            for(int i=0; i<bfs_size; i++){
                int t = bfs.front(); bfs.pop_front();
                if(nodes.find(t) == nodes.end()){
                    bfs.push_back(t);
                }else{
                    left_bfs.push_back(t);
                }
            }
        }
        // search(left_bfs, left_dfs);

        cout<<"left_bfs:";
        for(auto const & p : left_bfs) cout<<" "<<p;
        cout<<endl;

        cout<<"left_dfs:";
        for(auto const & p : left_dfs) cout<<" "<<p;
        cout<<endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n_str, t;
    deque<int> bfs, dfs;
    
    cin>>n_str;
    for(int i=0; i<n_str; i++){
        cin>>t;
        bfs.push_back(t);
    }
    for(int i=0; i<n_str; i++){
        cin>>t;
        dfs.push_back(t);
    }
    search(bfs, dfs);

    for(auto const & e : children_map){
        cout<<e.first<<":";
        for(int i=0; i<e.second.size(); i++) cout<<" "<<e.second[i];
        cout<<endl;
    }
}

/*
8
4 3 5 1 2 8 7 6
4 3 1 7 2 6 5 8
*/