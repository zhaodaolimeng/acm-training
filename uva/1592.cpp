#include <bits/stdc++.h>

// getline problem ???

using namespace std;

vector<vector<string>> vvs;
map<pair<string, string>, int> mp;

void print_vvs(){
    cout<<"=="<<endl;
    for(vector<string> vs : vvs){
        for(string s : vs)
            cout<<s<<"\t";
        cout<<endl;
    }
}

int main(){

    int rows, cols;
    int r1, r2, cc1, cc2;

    while(cin>>rows>>cols){
        vvs.clear();
        string s;
        for(int i=0; i<rows; i++){
            cin.ignore();  // 忽略\n
            getline(cin, s);
            stringstream ss(s);
            vector<string> ans;
            while(ss.good()){
                string substr;
                getline(ss, substr, ',');
                ans.push_back(substr);
            }
            // for(string s : ans) cout<<s<<endl;
            vvs.push_back(ans);
            // print_vvs();
        }

        bool found = false;
        for(int c1=0; c1<cols; c1++){
            for(int c2=c1+1; c2<cols; c2++){
                mp.clear();
                for(int r=0; r<rows; r++){
                    pair<string, string> p = make_pair(vvs[r][c1], vvs[r][c2]);
                    if(mp.find(p) == mp.end()){
                        mp[p] = r;
                    }else{
                        r1 = mp[p], r2 = r, cc1 = c1, cc2 = c2;
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) break;
        }
        if(found){
            cout<<"NO"<<endl;
            cout<<r1 + 1<<" "<<r2 + 1<<"\n"<<cc1 + 1<<" "<<cc2 + 1<<endl;
        }else cout<<"YES"<<endl;
    }
}

/*
3 3
How to compete in ACM ICPC,Peter,peter@neerc.ifmo.ru
How to win ACM ICPC,Michael,michael@neerc.ifmo.ru
Notes from ACM ICPC champion,Michael,michael@neerc.ifmo.ru
2 3
1,Peter,peter@neerc.ifmo.ru
2,Michael,michael@neerc.ifmo.ru

NO
2 3
2 3
YES
*/