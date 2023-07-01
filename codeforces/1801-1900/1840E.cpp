#include<bits/stdc++.h>

using namespace std;

int main(){

    int T,t,q,n,c,c1,c2,p1,p2;
    vector<string> s(2);
    std::cin>>T;

    while(T--){
        std::cin>>s[0]>>s[1];
        std::cin>>t>>q;

        vector<int> block(s[0].size(),0);
        vector<set<int> > clk(t,set<int>());
        int p = 0; // clock pointer

        for(int i=0;i<q;i++){
            std::cin>>c;
            // std::cout<<"----"<<endl;
            
            if(c == 1){
                // add block
                // std::cout<<"add block"<<endl;
                std::cin>>p1;
                block[p1-1] ++;
                clk[p].insert(p1-1);
            }else if(c == 2){
                // swap
                // std::cout<<"swap"<<endl;
                std::cin>>c1>>p1>>c2>>p2;
                char cc = s[c1-1][p1-1];
                s[c1-1][p1-1] = s[c2-1][p2-1];
                s[c2-1][p2-1] = cc;
            }else{
                // query
                // std::cout<<"query"<<endl;
                bool ok = true;
                for(int j=0;j<s[0].size();j++){
                    if(s[0][j] != s[1][j] && block[j]==0){
                        ok = false;
                        break;
                    }
                }
                if(ok) std::cout<<"YES"<<endl;
                else std::cout<<"NO"<<endl;
            }

            // for(int j=0;j<block.size();j++) std::cout<<block[j]<<'\t';
            // std::cout<<endl;

            // remove block
            p++;
            if(p == clk.size()) p=0;
            if(!clk[p].empty()){
                for(auto sp : clk[p]) block[sp]--;
            }

            // for(int j=0;j<block.size();j++) std::cout<<block[j]<<'\t';
            // std::cout<<endl;
            // std::cout<<"+++++"<<endl;
        }
    }
    return 0;
}