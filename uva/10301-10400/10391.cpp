#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<string> vs;
    string s;
    while(cin>>s) vs.push_back(s);

    set<string> dict(vs.begin(), vs.end());

    for(string s : vs){
        for(int i=1; i<s.size(); i++){
            if(dict.find(s.substr(0, i)) != dict.end() && 
                dict.find(s.substr(i, s.size()-i)) != dict.end()){
                cout<<s<<endl;
                break;
            }
        }
    }

}