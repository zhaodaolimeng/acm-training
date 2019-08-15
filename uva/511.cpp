#include <bits/stdc++.h>

using namespace std;

const float eps = 1e-6;

struct Map{
    float x1, y1, x2, y2;
    float area;
    string name;
};

vector<Map> maps;
map<string, pair<float,float>> locs;

inline float dist(float x1, float x2, float y1, float y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void process_query_location(string loc_name, int detail_level){
    if(locs.find(loc_name) == locs.end()){
        printf("%s at detail level %d unknown location\n",
            loc_name.c_str(), detail_level);
        return ;
    }

    pair<float, float> loc = locs[loc_name];
    vector<Map> cand, cand0;
    for(int i=0; i<maps.size(); i++){
        if(loc.first > maps[i].x1 && loc.first < maps[i].x2 &&
            loc.second > maps[i].y1 && loc.second < maps[i].y2)
            cand.push_back(maps[i]);
    }

    if(cand.size() == 0){
        printf("%s at detail level %d no map contains that location\n",
            loc_name.c_str(), detail_level);
        return ;
    }

    sort(cand.begin(), cand.end(), [&](Map& left, Map& right){
        if(abs(left.area - right.area) > eps){
            return left.area > right.area;
        }else{
            float xl = (left.x1 + left.x2)/2, yl = (left.y1 + left.y2)/2;
            float xr = (right.x1 + right.x2)/2, yr = (right.y1 + right.y2)/2;
            float left_dist = dist(loc.first, xl, loc.second, yl);
            float right_dist = dist(loc.first, xr, loc.second, yr);
            if(abs(left_dist - right_dist) > eps) return left_dist > right_dist;

            float ratiol = abs((left.y2 - left.y1)/(left.x2 - left.x1) - 0.75);
            float ratior = abs((right.y2 - right.y1)/(right.x2 - right.x1) - 0.75);
            if(abs(ratiol - ratior) > eps) return ratiol > ratior;

            left_dist = dist(loc.first, left.x2, loc.second, left.y1);
            right_dist = dist(loc.first, right.x2, loc.second, right.y1);
            if(abs(left_dist - right_dist) > eps) return left_dist < right_dist;
            return left.x1 < right.x1;
        }
    });

    // cout<<"-----"<<endl;
    // for(auto it=cand.begin(); it!=cand.end(); it++)
    //     cout<<"\t"<<it->name<<" "<<it->area<<endl;
    // cout<<"+++++"<<endl;

    vector<vector<Map>> cand_per_level;
    for(int i=0; i<cand.size(); i++){
        if(cand[i-1].area - cand[i].area > eps || i==0){
            vector<Map> vm;
            vm.push_back(cand[i]);
            cand_per_level.push_back(vm);
        }else
            cand_per_level[cand_per_level.size()-1].push_back(cand[i]);
    }
    // cout<<cand_per_level.size()<<" "<<cand_per_level[0].size()<<endl;

    Map target;
    if(cand_per_level.size() >= detail_level){
        cand0 = cand_per_level[detail_level-1];
        target = cand0[cand0.size()-1];
        printf("%s at detail level %d using %s\n",
            loc_name.c_str(), detail_level, target.name.c_str());
    }else{
        cand0 = cand_per_level[cand_per_level.size()-1];
        target = cand0[cand0.size()-1];
        printf("%s at detail level %d no map at that detail level; using %s\n",
            loc_name.c_str(), detail_level, target.name.c_str());
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s;
    cin>>s;

    while(true){
        if(s == "MAPS"){
            while(cin>>s && s != "LOCATIONS"){
                Map m;
                cin>>m.x1>>m.y1>>m.x2>>m.y2;
                if(m.x1 > m.x2) swap(m.x1, m.x2);
                if(m.y1 > m.y2) swap(m.y1, m.y2);
                m.name = s;
                m.area = (m.x2-m.x1) * (m.y2-m.y1);
                maps.push_back(m);
            }
        }else if(s == "LOCATIONS"){
            while(cin>>s && s != "REQUESTS"){
                pair<float, float> p;
                cin>>p.first>>p.second;
                locs[s] = p;
            }
        }else if(s == "REQUESTS"){
            while(cin>>s && s != "END"){
                int detail_level;
                cin>>detail_level;
                process_query_location(s, detail_level);
            }
            break;
        }
    }
}