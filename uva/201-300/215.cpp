#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

const int nan_ = (1<<30);

vector<vector<int>> cells;
map<string, string> idx_to_expr;
map<string, int> idx_to_val;
set<string> vis;

int evaluate_expr(string idx_str){
    // sleep_until(system_clock::now() + milliseconds(100));
    // cout<<"====="<<endl;
    // cout<<idx_str<<endl;
    // cout<<"+++++"<<endl;
    // for(const auto& p : idx_to_val) cout<<p.first<<" "<<p.second<<endl;
    // cout<<"-----"<<endl;
    
    if(idx_to_expr.find(idx_str) != idx_to_expr.end()) {
        if(vis.find(idx_str) != vis.end()){
            if(idx_to_val.find(idx_str) != idx_to_val.end() && idx_to_val[idx_str] != nan_)
                return idx_to_val[idx_str];
            idx_to_val[idx_str] = nan_;
            // cout<<idx_str<<": "<<idx_to_expr[idx_str]<<"="<<nan_<<endl;
            return nan_;
        }
        vis.insert(idx_str);
    } else
        return cells[idx_str[0]-'A'][idx_str[1]-'0'];

    string expr = idx_to_expr[idx_str];
    int ans = 0;
    string cur_idx = "";
    int cur_d = 0;
    bool cur_is_ref = false;
    int sym_before = 1;

    for(int p=0; p<=expr.size(); p++){
        if(p == expr.size() || expr[p] == '+' || expr[p] == '-'){
            if(cur_is_ref){
                int t = evaluate_expr(cur_idx);
                if(t == nan_) {
                    idx_to_val[idx_str] = nan_;
                    return nan_;
                }
                ans += t*sym_before;
            }else
                ans += cur_d*sym_before;
            
            if(p != expr.size()){
                if(expr[p] == '+') sym_before = 1;
                else sym_before = -1;
            }
            cur_d = 0;
            cur_idx = "";
            cur_is_ref = false;
        }else if(expr[p] >= 'A' && expr[p] <= 'Z'){
            cur_is_ref = true;
            cur_idx += expr[p];
        }else{
            if(cur_is_ref){
                cur_idx += expr[p];
            }else {
                cur_d *= 10;
                cur_d += expr[p] - '0';
            }
        }
    }
    // cout<<idx_str<<": "<<idx_to_expr[idx_str]<<"="<<ans<<endl;
    cells[idx_str[0]-'A'][idx_str[1]-'0'] = ans;
    idx_to_val[idx_str] = ans;
    return ans;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int R, C;
    string line;

    while(cin>>R>>C && R != 0){
        cells.clear();
        idx_to_expr.clear();
        idx_to_val.clear();
        vis.clear();
        for(int i=0; i<R; i++) cells.push_back(vector<int>(C));

        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                cin>>line;
                bool contains_exp = false;
                int sym_cnt = 0;
                for(char ch : line){
                    if(ch >= 'A' && ch <= 'T'){
                        contains_exp = true;
                        break;
                    } else if(ch == '+' || ch == '-'){
                        sym_cnt++;
                        if(sym_cnt == 2) break;
                    }
                }
                if(contains_exp || sym_cnt == 2){
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

        for(const auto &entry : idx_to_expr)
            if(vis.find(entry.first) == vis.end()){
                evaluate_expr(entry.first);
                // cout<<"+++++"<<endl;
                // for(const auto& p : idx_to_val) cout<<p.first<<" "<<p.second<<endl;
                // cout<<"-----"<<endl;
            }
        
        bool isall = true;
        for(const auto &entry : idx_to_val){
            if(entry.second == nan_) {
                isall = false;
                break;
            }
        }

        // cout<<"-----"<<endl;
        // for(const auto& entry : idx_to_val)
        //     cout<<entry.first<<": "<<entry.second<<endl;
        // cout<<"-----"<<endl;

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
            for(const auto& entry : idx_to_val){
                if(entry.second == nan_)
                    cout<<entry.first<<": "<<idx_to_expr[entry.first]<<endl;
            }
        }
        cout<<endl;
    }
}