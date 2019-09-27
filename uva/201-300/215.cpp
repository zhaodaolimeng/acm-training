#include <bits/stdc++.h>
// #include <chrono>
// #include <thread>

using namespace std;
//using namespace std::this_thread;
//using namespace std::chrono;
//sleep_until(system_clock::now() + milliseconds(10));

const int nan_ = (1<<30);

vector<vector<int>> cells;
map<string, string> idx_to_expr;
set<string> hit;

int evaluate_expr(string idx_str){
    if(hit.find(idx_str) == hit.end()) hit.insert(idx_str);
    else return nan_;
    
    int ans = 0;
    string cur_idx = "";
    int cur_d = 0;
    bool cur_is_ref = false;

    for(int p=0; p<=idx_str.size(); p++){
        if(p == idx_str.size() || idx_str[p] == '+' || idx_str[p] == '-'){
            if(cur_is_ref){
                int t = evaluate_expr(cur_idx);
                if(t == nan_) return nan_;
                else ans += t;
                cur_idx = "";
            }else{
                ans += cur_d;
                cur_d = 0;
            }
            cur_is_ref = false;
        }else if(idx_str[p] >= 'A' && idx_str[p] <= 'Z'){
            cur_is_ref = true;
            cur_idx += idx_str[p];
        }else{
            if(cur_is_ref){
                cur_idx += idx_str[p];
            }else {
                cur_d *= 10;
                cur_d += idx_str[p] - '0';
            }
        }
    }
    return ans;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int R, C;
    string line;

    while(cin>>R>>C && R != 0){
        cells.clear();
        idx_to_expr.clear();
        hit.clear();
        for(int i=0; i<R; i++) cells.push_back(vector<int>(C));

        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                cin>>line;
                bool contains_exp = false;
                for(char ch : line){
                    if(ch >= 'A' && ch <= 'T'){
                        contains_exp = true;
                        break;
                    }
                }
                if(contains_exp){
                    string idx(1, (char)('A' + r));
                    idx += to_string(c);
                    idx_to_expr[idx] = line;
                }else{
                    int d=0, i=0;
                    if(line[0] == '-') i++;
                    for(; i<line.size(); i++) {
                        d *= 10;
                        d += line[i] - '0';
                    }
                    if(line[0] == '-') d = -d;
                    cells[r][c] = d;
                }
            }
        }

        cout<<"**********"<<endl;
        for(const auto &entry : idx_to_expr)
            cout<<entry.first<<" "<<entry.second<<endl;

        for(const auto &entry : idx_to_expr)
            if(hit.find(entry.first) == hit.end())
                evaluate_expr(entry.first);
        
        bool isall = true;
        for(const auto & entry : idx_to_expr){
            if(hit.find(entry.first) == hit.end()){
                isall = false;
                break;
            }
        }

        if(isall){
            cout<<" ";
            for(int c=0; c<C; c++) cout<<"     "<<c;
            cout<<endl;
            for(int r=0; r<R; r++){
                cout<<(char)('A'+r);
                for(int c=0; c<C; c++){
                    string ds = to_string(cells[r][c]);
                    for(int i=0; i<6-ds.size(); i++)cout<<" ";
                    cout<<ds;
                }
                cout<<endl;
            }
        }else{
            for(const auto & entry : idx_to_expr){
                if(hit.find(entry.first) == hit.end())
                    cout<<entry.first<<": "<<entry.second<<endl;
            }
        }
        cout<<endl;
    }
}