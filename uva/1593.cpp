#include <bits/stdc++.h>

using namespace std;

void print_space(int n){
    for(int i=0; i<n; i++) cout<<" ";
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);

    vector<int> max_width;
    vector<vector<string>> codes;

    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        vector<string> ans;
        string substr;
        
        for(int i=0; ss>>substr; i++){
            ans.push_back(substr);
            if(i >= max_width.size())
                max_width.push_back(substr.size());
            else if(substr.size() > max_width[i])
                max_width[i] = substr.size();
        }
        codes.push_back(ans);
    }
    

    for(vector<string> vs : codes){
        for(int i=0; i<vs.size(); i++){
            cout<<vs[i];
            if(i != vs.size() - 1)
                print_space(max_width[i] - vs[i].size() + 1);
        }
        cout<<endl;
    }
    
}

/*
  start:  integer;    // begins here
stop: integer; //  ends here
 s:  string;
c:   char; // temp

start: integer; // begins here
stop:  integer; // ends   here
s:     string;
c:     char;    // temp
*/