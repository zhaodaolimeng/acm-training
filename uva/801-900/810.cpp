#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


vector<vector<int>> maze;
vector<vector<bool>> states[6][6];
vector<pair<int,int>> trace;
map<pair<int,int>, vector<int>> rotate_map;

int R, C, r_start, c_start;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void init(){
    rotate_map[make_pair(1,2)] = {2,5,3,4};
    rotate_map[make_pair(6,2)] = {2,5,4,3};
    rotate_map[make_pair(1,3)] = {3,4,5,2};
    rotate_map[make_pair(6,3)] = {3,4,2,5};
    rotate_map[make_pair(1,4)] = {4,3,2,5};
    rotate_map[make_pair(6,4)] = {4,3,5,2};
    rotate_map[make_pair(1,5)] = {5,2,4,3};
    rotate_map[make_pair(6,5)] = {5,2,3,4};

    rotate_map[make_pair(2,1)] = {1,6,4,3};
    rotate_map[make_pair(5,1)] = {1,6,3,4};
    rotate_map[make_pair(2,3)] = {3,4,1,6};
    rotate_map[make_pair(5,3)] = {3,4,6,1};
    rotate_map[make_pair(2,4)] = {4,3,6,1};
    rotate_map[make_pair(5,4)] = {4,3,1,6};
    rotate_map[make_pair(2,6)] = {6,1,3,4};
    rotate_map[make_pair(5,6)] = {6,1,4,3};

    rotate_map[make_pair(3,1)] = {1,6,2,5};
    rotate_map[make_pair(4,1)] = {1,6,5,2};
    rotate_map[make_pair(3,2)] = {2,5,6,1};
    rotate_map[make_pair(4,2)] = {2,5,1,6};
    rotate_map[make_pair(3,5)] = {5,2,1,6};
    rotate_map[make_pair(4,5)] = {5,2,6,1};
    rotate_map[make_pair(3,6)] = {6,1,5,2};
    rotate_map[make_pair(4,6)] = {6,1,2,5};
}

bool dfs(int r, int c, int t_, int f){
    // sleep_until(system_clock::now() + milliseconds(10));

    // cout<<"====="<<endl;
    // cout<<"top="<<t_<<" front="<<f<<" r="<<r+1<<" c="<<c+1<<endl;
    // cout<<"Trace: ";
    // for(auto const & p : trace) printf("[%d,%d]", p.first+1, p.second+1);
    // cout<<endl;

    // cout<<"-----"<<endl;
    if(r_start-1 == r && c_start-1 == c && !trace.empty()) {
        trace.push_back(make_pair(r,c));
        return true;
    }
    trace.push_back(make_pair(r,c));
    states[t_-1][f-1][r][c] = true;
    // cout<<"+++++"<<endl;

    vector<int> next_bottom = rotate_map[make_pair(t_,f)];
    for(int i=0; i<4; i++){
        int r_ = r + dr[i], c_ = c + dc[i];
        if(r_ < 0 || r_ >= R || c_ < 0 || c_ >= C) continue;
        if(maze[r_][c_] == t_ || maze[r_][c_] == -1){
            int f_, tt_;
            if(i == 0) f_ = 7 - t_;
            else if(i == 1) f_ = t_;
            else f_ = f;
            tt_ = next_bottom[i];
            if(states[tt_-1][f_-1][r_][c_] && !(r_ == r_start-1 && c_ == c_start-1)) continue;

            // cout<<i<<endl;
            // cout<<"top="<<t_<<" front="<<f<<" top_="<<tt_<<" front_="<<f_<<" r="<<r_+1<<" c="<<c_+1<<endl;

            bool result = dfs(r_, c_, tt_, f_);
            if(result) return true;
        }
    }
    trace.pop_back();
    return false;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string maze_name;
    int top_, face_, t;
    init();

    while(cin>>maze_name && maze_name != "END"){
        cin>>R>>C>>r_start>>c_start>>top_>>face_;
        for(int i=0; i<6; i++)
            for(int j=0; j<6; j++){
                states[i][j].clear();
                states[i][j] = vector<vector<bool>>();
                for(int r=0; r<R; r++) 
                    states[i][j].push_back(vector<bool>(C, false));
            }

        maze.clear();
        trace.clear();
        
        for(int i=0; i<R; i++){
            maze.push_back(vector<int>());
            for(int j=0; j<C; j++){
                cin>>t;
                maze[i].push_back(t);
            }
        }
        bool result = dfs(r_start-1, c_start-1, top_, face_);
        cout<<maze_name<<endl;
        cout<<"  ";
        if(result){
            for(int i=0; i<trace.size(); i++){
                if(i!=0 && i%9==0) cout<<"\n  ";
                cout<<"("<<1+trace[i].first<<","<<1+trace[i].second<<")";
                if(i!=trace.size()-1)cout<<",";
            }
        }else{
            cout<<"No Solution Possible";
        }
        cout<<endl;
        // cout<<"***********"<<endl;
    }
}
