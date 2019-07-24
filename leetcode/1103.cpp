#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back

typedef long long ll;
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        vector<int> ans;
        int t = label, b = 0;
        
        while(t > 0){
            t = (t >> 1);
            b ++;
        }

        t = label;
        for(int i=b-1; i>=0; i--){
            ans.push_back(t);
            t = (1<<(i+1)) - t + (1<<(i)) - 1;
                t /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution sl;

    int label = 26;
    vector<int> ans = sl.pathInZigZagTree(label);
    for(int a : ans){
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}