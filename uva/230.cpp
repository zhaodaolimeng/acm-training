#include <bits/stdc++.h>

using namespace std;


int find_books_by_name(vector<pair<string,string>> books, string name){
    // return lower_bound(books.begin(), books.end(), name, [](
    //     pair<string, string> &left, string name){
    //     return left.first < name;
    // }) - books.begin();
    for(int i=0; i<books.size(); i++)
        if(books[i].first == name)
            return i;
    return -1;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<pair<string, string>> books;
    vector<bool> exist;
    string cmd, name, author;

    while(getline(cin, cmd) && cmd != "END"){
        int quota = 0;
        for(int i=0; i<cmd.size(); i++){
            if(cmd[i] == '"') quota++;
            if(quota == 2){
                name = cmd.substr(0, i+1);
                author = cmd.substr(i+5, cmd.size()-i-4);
                break;
            }
        }
        books.push_back(make_pair(name, author));
        exist.push_back(true);
    }

    sort(books.begin(), books.end(), [](
        pair<string, string> &left, pair<string, string> &right){
        if(left.second == right.second) return left.first < right.first;
        return left.second < right.second;
    });
    // for(pair<string, string> p : books) cout<<p.first<<"|"<<p.second<<endl;
    // cout<<"======="<<endl;
    // cout<<books.size()<<endl;
    // cout<<find_books_by_name(books, "\"A House for Mr. Biswas\"")<<endl;

    int id;
    vector<int> rid;

    while(getline(cin, cmd) && cmd != "END"){
        if(cmd[0] == 'B' || cmd[0] == 'R') {
            name = cmd.substr(7, cmd.size() - 7);
            id = find_books_by_name(books, name);
        } 
        if(cmd[0] == 'B'){
            // cout<<name<<" "<<id<<endl;
            exist[id] = false;
        }else if(cmd[0] == 'R'){
            rid.push_back(id);
        }else{
            // for(int i=0; i<exist.size(); i++) cout<<exist[i]<<" ";
            // cout<<endl;

            sort(rid.begin(), rid.end());
            for(int i=0; i<rid.size(); i++){
                int j = rid[i] - 1;
                for(; j>=0; j--) if(exist[j]) break;

                if(j >= 0) cout<<"Put "<<books[rid[i]].first<<" after "<<books[j].first<<endl;
                else cout<<"Put "<<books[rid[i]].first<<" first"<<endl;
                exist[rid[i]] = true;
            }
            cout<<"END"<<endl;
            rid.clear();
        }
    }
}