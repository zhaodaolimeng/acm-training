#include<bits/stdc++.h>

using namespace std;


// Trie树
struct Node{
    int id;
    Node * next[10];
    Node():id(-1){
        for(int i = 0; i < 10; ++i)
            next[i] = NULL;
    }
};

Node * const root = new Node();

void add_node(char *str, int id) {
    Node * u = root;
    for(int i = 0, len = strlen(str); i < len && i <= 40; ++i){
        int v = str[i] - '0';
        if(!u->next[v])
            u->next[v] = new Node();
        u =  u->next[v];
        if(u->id == -1) u->id = id;
    }
}

int query(char *str) {
    Node * u = root;
    for(size_t i = 0, len = strlen(str); i < len; ++i){
        u = u->next[str[i]-'0'];
        if(!u) return -1;
    }
    return u->id;
}