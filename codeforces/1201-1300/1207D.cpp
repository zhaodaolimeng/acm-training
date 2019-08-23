#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

vector<pair<int,int>> vp;

int cmp1(pair<int,int> left, pair<int,int>right){
    return left.first<right.first;
}

int cmp2(pair<int,int> left, pair<int,int>right){
    return left.second<right.second;
}

int cmp3(pair<int,int> left, pair<int,int>right){
    if(left.first==right.first)
        return left.second<right.second;
    return left.first<right.first;
}

int main(){

    int n, a, b;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        vp.push_back(make_pair(a, b));
    }

    long long n1=0, n2=0, n3=0, cnt=1;

    sort(vp.begin(), vp.end(), cmp1);

    for(int i=1; i<vp.size(); i++){
        if(vp[i].first == vp[i-1].first) {
            n1 = (n1*cnt) % MOD;
            cnt++;
        }else{
            cnt = 1;
        }
    }

    sort(vp.begin(), vp.end(), cmp2);
    cnt = 1;
    for(int i=1; i<vp.size(); i++){
        if(vp[i].second == vp[i-1].second) {
            n2 = (n2*cnt) % MOD;
            cnt++;
        }else{
            cnt = 1;
        }
    }

    sort(vp.begin(), vp.end(), cmp3);
    cnt = 1;
    for(int i=1; i<vp.size(); i++){
        if(vp[i].first == vp[i-1].first && vp[i].second == vp[i-1].second) {
            n3 = (n3*cnt) % MOD;
            cnt++;
        }else{
            cnt = 1;
        }
    }

    long long ans = 1;
    for(int i=1; i<=vp.size(); i++){
        ans = (ans + i) % MOD;
    }

    cout<<(ans - n1/n3*n2 + MOD) % MOD<<endl;
}