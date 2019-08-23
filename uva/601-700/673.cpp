#include <bits/stdc++.h>

using namespace std;

bool check_balance(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(st.top() == '(' && s[i] == ')' || 
            st.top() == '[' && s[i] == ']'){
            st.pop();
        }else if(st.top() == '(' && s[i] == ']' ||
            st.top() == '[' && s[i] == ')'){
            return false;
        }else
            st.push(s[i]);
    }
    if(st.empty()) return true;
    return false;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin>>n;
    cin.ignore();
    while(n--){
        getline(cin, s);
        if(s.empty()) s = "";
        if(check_balance(s)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}