#include <bits/stdc++.h>

using namespace std;


// 直接参考了这份报告：http://acm.zzkun.com/archives/21

const int max_f = 100000;

int F[2][7*max_f];
// 这只是Fib数列的存储，真正打的表直接存储于Trie树中。F[2]是一个滚动。
// 如果采用十进制的话，总的数据量应该为比max_f多6个数量级以上。
char Fib[50], In[50];  

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

void init() {
    memset(F, 0, sizeof(F));
    F[0][0] = F[1][0] = 1;
    int s = 0, e = 1;
    add_node((char *)"1", 0);
    add_node((char *)"1", 1);
    for(int i = 2; i < max_f; ++i){
        int p = i%2, q = (i+1)%2;
        // 滚动计算，F[0]或F[1]均为一个Fib数
        for(int j = s; j < e; ++j) F[p][j] += F[q][j];
        for(int j = s; j < e; ++j)
            if(F[p][j]>=10){
                 F[p][j] %= 10;
                 F[p][j+1] += 1;
            }
        if(F[p][e]) ++e;
        if(e - s > 50) ++s;
        int r = e - 1, cnt = 0;
        memset(Fib, 0, sizeof(Fib));
        while(r >= 0 && cnt<45) Fib[cnt++] = F[p][r--] + '0';
        add_node(Fib, i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    string s;
    init();
    for(int i=1; i<=n; i++){
        cin>>In;
        int ans = query(In);
        printf("Case #%d: %d\n", i, ans);
    }
}