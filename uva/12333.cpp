#include <bits/stdc++.h>

using namespace std;

struct BigInteger {
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger(long long num=0){
        *this = num;
    }

    BigInteger operator=(long long num){
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }

    BigInteger operator=(const string& str){
        s.clear();
        int x, len = (str.length()-1)/WIDTH + 1;
        for(int i=0; i<len; i++){
            int end = str.length() - i*WIDTH;
            int start = max(0, end-WIDTH);
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator+(const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        for(int i=0, g=0; ; i++){
            if(g==0 && i>=s.size() && i>b.s.size()) break;
            int x = g;
            if(i<s.size()) x+=s[i];
            if(i<b.s.size()) x+=b.s[i];
            c.s.push_back(x%BASE);
            g = x/BASE;
        }
        return c;
    }

    BigInteger operator += (const BigInteger& b){
        *this = * this + b;
        return *this;
    }

    bool operator < (const BigInteger& b) const {
        if(s.size() != b.s.size()) return s.size()<b.s.size();
        for(int i=s.size()-1; i>=0; i--)
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }

    bool operator > (const BigInteger& b) const {
        return b < *this;
    }

    bool operator == (const BigInteger& b) const {
        if(s.size() != b.s.size()) return false;
        for(int i=s.size()-1; i>=0; i--)
            if(s[i] != b.s[i]) return false;
        return true;
    }

    bool first_integer_match(const string& str){
        int si = 0;
        for(int i=s.size()-1; i>=0; i--){
            string ts = to_string(s[i]);
            for(int j=0; j<ts.size(); j++){
                if(ts[j] != str[si]) return false;
                si++;
                if(si == str.size()) break;
            }
            if(si == str.size()) break;
        }
        return true;
    }

};

int search_frist_match(string s){
    if(s == "1") return 0;
    BigInteger a0, a1, a2;
    a0 = 1, a1 = 1;
    for(int i=2; i<100000; i++){
        a2 = a0 + a1;
        if(a2.first_integer_match(s)) return i;
        a0 = a1, a1 = a2;
    }
    return -1;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    string s;
    for(int i=1; i<=n; i++){
        cin>>s;
        int ans = search_frist_match(s);
        printf("Case #%d: 0\n", ans);
    }
}