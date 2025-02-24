#include <bits/stdc++.h>

using namespace std;

// 6
// a b c aa d b
// 1 2 3 4 5 6
// 3
// 1 5 caaab
// 0 4 xyz
// 2 4 bcdybc

struct Node{
    Node* next[26];
    bool isleaf;
    vector<pair<int,int>> val;
    Node(){
        for(int i=0;i<26;i++) next[i]=NULL;
        isleaf=false;
    };
};

Node* insert_item(int idx,string s,int v,Node* head){
    Node* p=head;
    if(p == NULL) p = new Node();

    bool exist=true;
    for(int i=0;i<s.size();i++){
        int c = s[i]-'a';
        if(p->next[c]==NULL){
            p->next[c] = new Node();
            exist=false;
        }
        p = p->next[c];
    }
    if(!exist) p->isleaf=true;
    p->val.push_back(make_pair(idx,v));
    return head;
}

Node* build_tree(vector<string>vs,vector<int>vi){
    Node *head;
    for(int i=0;i<vs.size();i++)
        head = insert_item(i,vs[i],vi[i],head);
    
    // sort vals at leaf node
    vector<Node> st;
    st.push_back(*head);
    while(st.size()>0){
        st.pop_back()
    }
    
}

Node* search(string s){
    
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(n_temp);

    string genes_temp_temp;
    getline(cin, genes_temp_temp);
    vector<string> genes_temp = split(genes_temp_temp);
    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];
        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);
    vector<string> health_temp = split(health_temp_temp);
    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);
        health[i] = health_item;
    }

    Node *head = build_tree(genes,health);

    string s_temp;
    getline(cin, s_temp);
    int s = stoi(s_temp);

    for (int s_itr = 0; s_itr < s; s_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(first_multiple_input_temp);
        int first = stoi(first_multiple_input[0]);
        int last = stoi(first_multiple_input[1]);
        string d = first_multiple_input[2];
         
        
    }

    return 0;
}


vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
