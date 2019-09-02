#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    list<vector<string>> ls;

    string s;
    while(cin>>s && s != "#"){
        ls.clear();
        vector<string> vs;
        vs.push_back(s);
        ls.push_back(vs);
        for(int i=0; i<51; i++){
            vs.clear();
            cin>>s;
            vs.push_back(s);
            ls.push_back(vs);
        }

        for(auto it = ls.begin(); it != ls.end(); it++){
            bool changed = false;
            auto it_left = it, it_peek = it;
            for(; it_left != ls.begin(); ){
                it_peek = it_left;
                int i = 0;
                for(i=0; i<3 && it_peek != ls.begin(); i++) it_peek = prev(it_peek);
                if((i==3) && 
                    ((*it_peek)[(*it_peek).size()-1][0] == (*it)[(*it).size()-1][0] || 
                    (*it_peek)[(*it_peek).size()-1][1] == (*it)[(*it).size()-1][1])){
                    it_left = it_peek;
                }else{
                    it_peek = prev(it_left);
                    // cout<<(*it_peek)[(*it_peek).size()-1]<<" "<<(*it_left)[(*it_left).size()-1]<<endl;
                    if((it_left != it_peek) &&
                        ((*it_peek)[(*it_peek).size()-1][0] == (*it)[(*it).size()-1][0] || 
                        (*it_peek)[(*it_peek).size()-1][1] == (*it)[(*it).size()-1][1])){
                        it_left = it_peek;
                    }else break;
                }
            }
            
            // cout<<(*it_left)[(*it_left).size()-1]<<" "<<(*it)[(*it).size()-1]<<endl;
            if(it_left != it){
                (*it_left).push_back((*it)[(*it).size()-1]);
                (*it).pop_back();
                changed = true;
            }
            if((*it).size() == 0) ls.erase(it);
            if(changed) it = it_left;
            
            // for(auto itt=ls.begin(); itt!=ls.end(); itt++) cout<<" "<<(*itt).size();
            // cout<<endl;
            // for(auto itt=ls.begin(); itt!=ls.end(); itt++){
            //     for(string s: (*itt)) cout<<s<<" ";
            //     cout<<"|| ";
            // }
            // cout<<endl;
        }
        
        if(ls.size() == 1) cout<<"1 pile remaining:";
        else cout<<ls.size()<<" piles remaining:";
        for(auto it=ls.begin(); it!=ls.end(); it++)
            cout<<" "<<(*it).size();
        cout<<endl;
    }
}