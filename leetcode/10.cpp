#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<string> pv;
        for(int i=p.size()-1;i>=0;){
            if(p[i]=='*') {
                pv.push_back(p.substr(i-1,2));
                i-=2;
            } else {
                pv.push_back(p.substr(i,1));
                i-=1;
            }
        }
        pv.push_back("^");
        reverse(pv.begin(),pv.end());
        string ps = "^" + s;

        // for(int i=0;i<pv.size();i++) cout<<pv[i]<<endl;
        // cout<<ps<<endl;

        vector<bool> match(ps.size()*2,false);
        match[0] = true;
        int i,j,k;

        for(i=1;i<pv.size();i++){
            if(i%2 == 1){
                if(pv[i].size()==1){
                    for(j=1;j<ps.size();j++){
                        if(match[j-1] && (ps[j]==pv[i][0] || pv[i][0] == '.')) 
                            match[j+ps.size()] = true;
                    }
                } else if(pv[i][0] == '.'){
                    for(j=0;j<ps.size()-1;j++){
                        if(match[j]) match[j+ps.size()] = true;
                        if(match[j+ps.size()]) match[j+ps.size()+1] = true;
                    }
                } else {
                    for(j=0;j<ps.size();j++){
                        if(match[j]) {
                            match[j+ps.size()] = true;
                            for(k=j+1;k<ps.size()&&ps[k] == pv[i][0];k++){
                                match[k+ps.size()] = true;
                            }
                            j = k - 1;
                        }
                    }
                }


                for(j=0;j<ps.size();j++) match[j]=false;
            } else {
                if(pv[i].size()==1){
                    for(j=1;j<ps.size();j++){
                        if(match[j+ps.size()-1] && (ps[j]==pv[i][0] || pv[i][0] == '.')) 
                            match[j] = true;
                    }
                } else if(pv[i][0] == '.'){
                    for(j=0;j<ps.size();j++){
                        if(match[j+ps.size()]) match[j] = true;
                        if(match[j]) match[j+1] = true;
                    }
                } else {
                    for(j=0;j<ps.size();j++){
                        if(match[j+ps.size()]) {
                            match[j] = true;
                            for(k=j+1;k<ps.size()&&ps[k] == pv[i][0];k++){
                                match[k] = true;
                            }
                            j = k - 1;
                        }
                    }
                }
                for(j=0;j<ps.size();j++) match[j+ps.size()]=false;
            }

            // for(int n=0; n<2; n++){
            //     for(int m=0; m<match.size()/2; m++) 
            //         cout<<match[n*(match.size()/2)+m]<<"\t";
            //     cout<<endl;
            // }
            // cout<<endl;

            
        }
        if(pv.size()%2==0) 
            return match[ps.size()*2-1];
        else 
            return match[ps.size()-1];
    }
};

int main(){
    Solution sl;
    cout<<sl.isMatch("aab","a*b")<<endl;
    cout<<sl.isMatch("aab","aab")<<endl;
    cout<<sl.isMatch("mississippi","mis*is*p*.")<<endl;
    cout<<sl.isMatch("mississippi","mis*is*ip*.")<<endl;
}
