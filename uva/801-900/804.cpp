#include <bits/stdc++.h>

using namespace std;

const int max_np = 105;
int NP, NT, NF, t;

vector<int> tokens;
vector<int> v_in, v_out;
vector<vector<int>> trans_in, trans_out;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int kase = 1;
    
    while(cin>>NP && NP != 0){
        tokens.clear(), trans_in.clear(), trans_out.clear();
        for(int i=0; i<NP; i++){
            cin>>t;
            tokens.push_back(t);
        }

        cin>>NT;
        for(int i=0; i<NT; i++){
            v_in.clear(), v_out.clear();
            while(cin>>t && t != 0){
                if(t < 0) v_in.push_back(-t-1);
                else v_out.push_back(t-1);
            }
            trans_in.push_back(v_in);
            trans_out.push_back(v_out);
        }

        // for(int i=0; i<trans_in.size(); i++){
        //     for(int j=0; j<trans_in[i].size(); j++) cout<<trans_in[i][j]<<" ";
        //     cout<<" ||| ";
        //     for(int j=0; j<trans_out[i].size(); j++) cout<<trans_out[i][j]<<" ";
        //     cout<<endl;
        // }

        cin>>NF;

        bool changed = true;
        int step = 1;

        while(step<=NF && changed){
            changed = false;
            // cout<<"-----"<<endl;

            for(int i=0; i<trans_in.size(); i++){
                bool ok = true;
                for(int j=0; j<trans_in[i].size(); j++){
                    if(tokens[trans_in[i][j]] == 0) ok = false;
                    tokens[trans_in[i][j]] --;
                }
                if(!ok) {
                    for(int j=0; j<trans_in[i].size(); j++) 
                        tokens[trans_in[i][j]] ++;
                }else{
                    changed = true;
                    step ++;
                    for(int j=0; j<trans_out[i].size(); j++)
                        tokens[trans_out[i][j]] ++;
                    if(step > NF) break;
                }
            }

            // for(int i=0; i<tokens.size(); i++) cout<<tokens[i]<<" ";
            // cout<<endl;
            // for(int i=0; i<tokens_add.size(); i++) cout<<tokens_add[i]<<" ";
            // cout<<endl;
        }

        if(changed){
            printf("Case %d: still live after %d transitions\n", kase, NF);
        } else{
            printf("Case %d: dead after %d transitions\n", kase, step-1);
        }
        
        printf("Places with tokens:");
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] != 0)
                printf(" %d (%d)", i+1, tokens[i]);
        }
        printf("\n\n");
        kase ++;
    }
}
