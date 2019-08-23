#include<bits/stdc++.h>

using namespace std;

void print_vec(vector<char> s){
    for(char c : s) cout<<c;
    cout<<endl;
}

vector<char> add(vector<char> s, int mid){
    vector<char> ret;
    int t, res=0;
    for(int i=mid-1, j=s.size()-1; i>=0 || j >=mid; i--, j--){
        t = res, res = 0;
        if(i >= 0) t+= s[i] - '0';
        if(j >= mid) t+= s[j] - '0';
        if(t>9) t-=10, res+=1;
        ret.push_back(t+'0');
    }
    if(res != 0) ret.push_back(res+'0');
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<char> smaller(vector<char> r1, vector<char> r2){
    if(r1.size() == r2.size()){
        for(int t1=0, t2=0; t1<r1.size(); t1++, t2++){
            if(r1[t1] == r2[t2]) continue;
            return (r1[t1] < r2[t2]) ? r1 : r2;
        }
        return r1;
    }
    return r1.size() < r2.size() ? r1 : r2;
}

vector<char> scan_zero_candidates(vector<char> &s, int m){
    int l = m, r = m;
    while(r < s.size() && s[r] == '0') r ++;
    while(l >= 0 && s[l] == '0') l --;
    
    vector<char> r1 = add(s, l);
    vector<char> r2 = add(s, r);
    if(l < 0) return r2;
    if(r >= s.size()) return r1;
    return smaller(r1, r2);
}

int main(){
    vector<char> s;
    int len, n, m;
    char c;

    cin>>len;
    for(int i=0; i<len; i++){
        cin>>c;
        s.push_back(c);
    }

    vector<char> max_vec, r1, r2;
    if(len&1){
        if(s[len>>1] != '0' && s[(len>>1)+1] != '0'){
            r1 = add(s, (len>>1));
            r2 = add(s, (len>>1) + 1);
            max_vec = smaller(r1, r2);
        }else{
            m = (len>>1);
            if(s[m] == '0')
                max_vec = scan_zero_candidates(s, m);
            m = (len>>1) + 1;
            if(s[m] == '0'){
                vector<char> t = scan_zero_candidates(s, m);
                max_vec = smaller(t, max_vec);
            }
        }
    }else{
        m = (len>>1);
        if(s[m] == '0'){
            max_vec = scan_zero_candidates(s, m);
        }else
            max_vec = add(s, m);
    }
    print_vec(max_vec);
    return 0;
}