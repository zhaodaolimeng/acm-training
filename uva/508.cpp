#include<bits/stdc++.h>

using namespace std;


const int maxn = 1000;

map<char, string> dictionary;
vector<string> context;
vector<string> context_morse;

string get_morse(string s){
    string ans;
    for(char c : s) ans += dictionary[c];
    return ans;
}

bool is_prefix(string l, string s){
    for(int i=0; i<s.size(); i++)
        if(l[i] != s[i]) return false;
    return true;
}

// string search_perfect(string morse){
//     string shortest;
//     int cnt = 0;
//     for(int i=0; i<context.size(); i++){
//         if(context_morse[i] == morse) {
//             if(shortest.size() == 0 || shortest.size() > context[i].size()){
//                 shortest = context[i];
//                 cnt ++;
//             }
//         }
//     }
//     if(cnt == 0) return "";
//     else if(cnt == 1) return shortest;
//     return shortest + "!";
// }

string search_perfect(string morse){
    int cnt = 0;
    string result;
    for(int i=0; i<context.size(); i++){
        if(context_morse[i] == morse) {
            if(cnt == 0) result = context[i];
            cnt ++;
        }
    }
    if(cnt == 0) return "";
    if(cnt == 1) return result;
    return result + "!";
}

string search_non_perfect(string morse){
    // 两种情况
    // 1. morse是context_morse[i]的前缀
    // 2. morse是context_morse[i]的扩展
    // 找到不同最小的
    int min_change = maxn, t;
    string result;
    for(int i=0; i<context.size(); i++){
        t = morse.size() - context_morse[i].size();
        if(t > 0){
            if(is_prefix(morse, context_morse[i])){
                min_change = min(min_change, t);
                result = context[i];
            }
        }else{
            if(is_prefix(context_morse[i], morse)){
                min_change = min(min_change, -t);
                result = context[i];
            }
        }
    }
    return result + "?";
}


int main(){

    char c;
    string s, morse;
    while(cin>>c && c != '*'){
        cin>>s;
        dictionary[c] = s;
    }
    while(cin>>s && s[0] != '*'){
        context.push_back(s);
        context_morse.push_back(get_morse(s));
    }
    
    while(cin>>morse && morse[0] != '*'){
        string result = search_perfect(morse);
        if(result == "") result = search_non_perfect(morse);
        cout<<result<<endl;
    }
}

/*

A .-
B -...
C -.-.
D -..
E .
F ..-.
G --.
H ....
I ..
J .---
K -.-
L .-..
M --
N -.
O ---
P .--.
Q --.-
R .-.
S ...
T -
U ..-
V ...-
W .--
X -..-
Y -.--
Z --..
0 ------
1 .-----
2 ..---
3 ...--
4 ....-
5 .....
6 -....
7 --...
8 ---..
9 ----.
*
AN
EARTHQUAKE
EAT
GOD
HATH
IM
READY
TO
WHAT
WROTH
*
.--.....-- .....--....
--.----.. .--.-.----..
.--.....-- .--.
..-.-.-....--.-..-.--.-.
..-- .-...--..-.--
---- ..--
*

WHAT
HATH
GOD
WROTH?
WHAT
AN
EARTHQUAKE
EAT!
READY
TO
EAT!
 */