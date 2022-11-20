#include<bits/stdc++.h>

using namespace std;

int nxt[100000][26];
int hit_cnt[100000];

void insert(string s){
    int p=0, L=s.size(), t=0;
    for(int i=0; i<L; i++){
        char c = s[i]-'a';
        if(!nxt[p][c]){
            t += 1;
            nxt[p][c] = t;
        }
        p = nxt[p][c];
    }
    hit_cnt[p] = 1;
}

int find(string s){
    int p=0, L=s.size();
    for(int i=0; i<L; i++){
        char c = s[i]-'a';
        if(!nxt[p][c]) return false;
        p = nxt[p][c];
    }
    return hit_cnt[p];
}



int main(){
    insert("abcabc");
    cout<<find("abcabc")<<endl;
    cout<<find("abcab")<<endl;
    return 0;
}
