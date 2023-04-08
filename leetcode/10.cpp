#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // bool isMatch(string s, string p) {
    //     vector<string> pv;
    //     for(int i=p.size()-1;i>=0;){
    //         if(p[i]=='*') {
    //             pv.push_back(p.substr(i-1,2));
    //             i-=2;
    //         } else {
    //             pv.push_back(p.substr(i,1));
    //             i-=1;
    //         }
    //     }
    //     pv.push_back("^");
    //     reverse(pv.begin(),pv.end());
    //     string ps = "^" + s;

    //     for(int i=0;i<pv.size();i++) cout<<pv[i]<<endl;
    //     cout<<ps<<endl;

    //     vector<bool> match(ps.size()*2,false);
    //     match[0] = true;
    //     int i,j,k;

    //     for(i=1;i<pv.size();i++){
    //         if(i%2 == 1){
    //             if(pv[i].size()==1){
    //                 for(j=1;j<ps.size();j++){
    //                     if(match[j-1] && (ps[j]==pv[i][0] || pv[i][0] == '.')) 
    //                         match[j+ps.size()] = true;
    //                 }
    //             } else if(pv[i][0] == '.'){
    //                 for(j=0;j<ps.size()-1;j++){
    //                     if(match[j]) match[j+ps.size()] = true;
    //                     if(match[j+ps.size()]) match[j+ps.size()+1] = true;
    //                 }
    //             } else {
    //                 for(j=0;j<ps.size();j++){
    //                     if(match[j]) {
    //                         match[j+ps.size()] = true;
    //                         for(k=j+1;k<ps.size()&&ps[k] == pv[i][0];k++){
    //                             match[k+ps.size()] = true;
    //                         }
    //                         j = k - 1;
    //                     }
    //                 }
    //             }


    //             for(j=0;j<ps.size();j++) match[j]=false;
    //         } else {
    //             if(pv[i].size()==1){
    //                 for(j=1;j<ps.size();j++){
    //                     if(match[j+ps.size()-1] && (ps[j]==pv[i][0] || pv[i][0] == '.')) 
    //                         match[j] = true;
    //                 }
    //             } else if(pv[i][0] == '.'){
    //                 for(j=0;j<ps.size();j++){
    //                     if(match[j+ps.size()]) match[j] = true;
    //                     if(match[j]) match[j+1] = true;
    //                 }
    //             } else {
    //                 for(j=0;j<ps.size();j++){
    //                     if(match[j+ps.size()]) {
    //                         match[j] = true;
    //                         for(k=j+1;k<ps.size()&&ps[k] == pv[i][0];k++){
    //                             match[k] = true;
    //                         }
    //                         j = k - 1;
    //                     }
    //                 }
    //             }
    //             for(j=0;j<ps.size();j++) match[j+ps.size()]=false;
    //         }

    //         // for(int n=0; n<2; n++){
    //         //     for(int m=0; m<match.size()/2; m++) 
    //         //         cout<<match[n*(match.size()/2)+m]<<"\t";
    //         //     cout<<endl;
    //         // }
    //         // cout<<endl;

            
    //     }
    //     if(pv.size()%2==0) 
    //         return match[ps.size()*2-1];
    //     else 
    //         return match[ps.size()-1];
    // }
    bool isMatch(string s, string p) {

        vector<string> pv;
        s = "^" + s;
        p = "^" + p;
        for(int i=0;i<p.size();i++){
            if(p[i] == '*') pv[pv.size()-1]+="*";
            else pv.push_back(p.substr(i,1));
        }
        vector<vector<bool> > dp(pv.size(),vector<bool>(s.size(),false));
        dp[0][0] = true;

        for(int i=0;i<pv.size();i++) cout<<pv[i]<<endl;

        for(int i=1; i<pv.size(); i++){
            if(pv[i].size() == 1){
                for(int j=1;j<s.size();j++){
                    if(pv[i] == "." || pv[i][0] == s[j])
                        dp[i][j] = dp[i-1][j-1];
                }
            }else{
                for(int j=1;j<s.size();j++){
                    if(dp[i-1][j-1]){
                        dp[i][j-1] = dp[i-1][j-1];
                        for(int k=j;k<s.size() && (s[k] == pv[i][0] || pv[i][0] == '.');k++){    
                            dp[i][k] = dp[i-1][j-1];
                        }
                    }
                }
            }
        }

        for(int i=0;i<pv.size();i++){
            for(int j=0;j<s.size();j++){
                cout<<dp[i][j]<<"\t";
            }
            cout<<endl;
        }
        
        return dp[pv.size()-1][s.size()-1];
    }
};

int main(){
    Solution sl;
    cout<<sl.isMatch("a","ab*")<<endl;
    // cout<<sl.isMatch("aab","a*b")<<endl;
    // cout<<sl.isMatch("aab","aab")<<endl;
    // cout<<sl.isMatch("mississippi","mis*is*p*.")<<endl;
    // cout<<sl.isMatch("mississippi","mis*is*ip*.")<<endl;
}
