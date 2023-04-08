#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {

        // stack num
        stack<char> st;
        stack<int> sv;
        st.push('^');
        sv.push(0);

        // 依次进栈，记录每个pop的合法长度t

        int ret = 0,t;
        for(int i=0; i<s.size(); i++){
            if(st.top() == '(' && s[i] == ')'){
                st.pop();
                t = 2;
                if(sv.top() > 0){
                    t = sv.top()+2;
                    sv.pop();
                }
                sv.pop();
                for(; sv.top()!=0; sv.pop()) t += sv.top();
                sv.push(t);
                ret = max(ret,sv.top());
            }else{
                st.push(s[i]);
                sv.push(0);
            }
        }
        return ret;
    }
};

int main(){

    Solution sl;

    string s;
    cin>>s;
    int ret = sl.longestValidParentheses(s);
    cout<<ret<<endl;

    return 0;
}

/*
()()
(())
(()()
()(())
*/