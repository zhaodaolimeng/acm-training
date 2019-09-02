#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    list<vector<string>> ls;
    vector<string> tvs;

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

        for(auto it=ls.begin(); it!=ls.end(); it++) cout<<(*it)[0]<<" ";
        cout<<endl;
        
        for(auto it = ls.begin(); it != ls.end(); it++){
            auto it_left = it, it_peek = it;
            for(; it_left != ls.begin(); ){
                it_peek = it_left;
                int i = 0;
                for(i=0; i<3 && it_peek != ls.begin(); i++) it_peek = prev(it_peek);
                if((i==3) && 
                    ((*it_peek)[(*it_peek).size()-1][0] == (*it_left)[(*it_left).size()-1][0] || 
                    (*it_peek)[(*it_peek).size()-1][1] == (*it_left)[(*it_left).size()-1][1])){
                    it_left = it_peek;
                }else{
                    it_peek = prev(it_left);
                    if((it_left != it_peek) &&
                        ((*it_peek)[(*it_peek).size()-1][0] == (*it_left)[(*it_left).size()-1][0] || 
                        (*it_peek)[(*it_peek).size()-1][1] == (*it_left)[(*it_left).size()-1][1])){
                        it_left = it_peek;
                    }else break;
                }
            }
            if(it_left != it){
                tvs = (*it);
                (*it_left).push_back(tvs[tvs.size()-1]);
                tvs.pop_back();
                if(tvs.size() == 0) ls.erase(it);
            }
            for(auto itt=ls.begin(); itt!=ls.end(); itt++) cout<<" "<<(*itt).size();
            cout<<endl;
        }
        if(ls.size() == 1) cout<<"1 pile remaining:";
        else cout<<ls.size()<<" piles remaining:";
        for(auto it=ls.begin(); it!=ls.end(); it++)
            cout<<" "<<(*it).size();
        cout<<endl;
    }
}