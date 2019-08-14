#include <bits/stdc++.h>

using namespace std;


vector<string> split_by_commas(string line){
    vector<string> ans;
    stringstream ss(line);
    while(ss.good()){
        string s;
        getline(ss, s, ',');
        ans.push_back(s);
    }
    return ans;
}

map<string,string> string_to_dict(string line){
    map<string, string> ans;
    line = line.substr(1, line.size()-2);
    if(line.size() == 0) return ans;
    vector<string> vp = split_by_commas(line);

    for(int i=0; i<vp.size(); i++){
        string s = vp[i];
        int colon_p = s.find(':');
        string key = s.substr(0, colon_p);
        string val = s.substr(colon_p+1, s.size()-colon_p-1);
        ans[key] = val;
    }
    return ans;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    string older, newer;
    map<string, string> omap, nmap;
    vector<string> addv, rmv, modv;

    for(int i=0; i<n; i++){
        cin>>older>>newer;
        omap = string_to_dict(older);
        nmap = string_to_dict(newer);
        addv.clear(); rmv.clear(); modv.clear();

        for(auto const & n : nmap){
            if(omap.find(n.first) == omap.end())
                addv.push_back(n.first);
            else if(n.second != omap[n.first]){
                modv.push_back(n.first);
            }
        }
        for(auto const & o : omap){
            if(nmap.find(o.first) == nmap.end())
                rmv.push_back(o.first);
        }
        if(addv.size()==0 && rmv.size()==0 && modv.size()==0) cout<<"No changes"<<endl;
        else{
            if(addv.size() != 0){
                cout<<"+";
                for(int i=0; i<addv.size(); i++){
                    if(i != 0) cout<<",";
                    cout<<addv[i];
                }
                cout<<endl;
            }
            if(rmv.size() != 0){
                cout<<"-";
                for(int i=0; i<rmv.size(); i++){
                    if(i != 0) cout<<",";
                    cout<<rmv[i];
                }
                cout<<endl;
            }
            if(modv.size() != 0){
                cout<<"*";
                for(int i=0; i<modv.size(); i++){
                    if(i != 0) cout<<",";
                    cout<<modv[i];
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
}