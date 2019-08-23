#include <bits/stdc++.h>

using namespace std;

struct Array{
    int size;
    map<int, int> val;
};

map<string, Array> array_map;

int get_array_value(string line, int start, int end){
    int p = start;
    if(line[end] == ']'){
        for(p=start; line[p] != '['; p++);
        string aname = line.substr(start, p-start);
        int idx = get_array_value(line, p+1, end-1);

        Array target = array_map[aname];
        if(idx >= target.size || target.val.find(idx) == target.val.end()) return -1;
        return target.val[idx];
    }else
        return stoi(line.substr(start, end-start+1));
}

bool check_line(string line){
    int p = 0, pe = -1;
    for(int i=0; i<line.size(); i++)
        if(line[i] == '=') {
            pe = i;
            break;
        }

    // cout<<pe<<endl;

    if(pe == -1){
        for(p=0; line[p] != '['; p++);
        string name = line.substr(0, p);
        int val = get_array_value(line, p+1, line.size()-2);

        // cout<<name<<" "<<val<<endl;

        if(val == -1) return false;

        Array new_a;
        new_a.size = val;
        array_map[name] = new_a;
    }else{
        string line0 = line.substr(0, pe);
        string line1 = line.substr(pe+1, line.size()-pe-1);

        // cout<<line0<<" "<<line1<<endl;
        
        for(p=0; line0[p] != '['; p++);

        string left_name = line0.substr(0, p);
        int val = get_array_value(line0, p+1, line0.size()-2);
        Array& target = array_map[left_name];

        if(val >= target.size) return false;

        int right_value = get_array_value(line1, 0, line1.size()-1);
        if(right_value == -1)  return false;

        // cout<<"val="<<val<<", right_value="<<right_value<<endl;
        target.val[val] = right_value;
        // cout<<"right_val should be: "<<array_map[left_name].val[val]<<endl;
    }
    return true;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string line, last_line;
    int bug_line = 0, line_cnt = 0;

    while(cin>>line){
        if(line[0] == '.') break;
        array_map.clear();
        int bug_line = 0, line_cnt = 0;
        do{
            // cout<<"====="<<endl;
            line_cnt ++;
            if(bug_line == 0 && !check_line(line))
                bug_line = line_cnt;
            
            // for(auto const & entry : array_map){
            //     cout<<entry.first<<" "<<entry.second.size<<endl;
            //     for(auto const & item : entry.second.val){
            //         cout<<"\t-\t"<<item.first<<" "<<item.second<<endl;
            //     }
            // }

        } while(cin>>line && line[0] != '.');
        cout<<bug_line<<endl;
    }
}