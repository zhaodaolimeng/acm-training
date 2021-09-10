#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {

        vector<int> div = {1000,500,100,50,10,5,1};
        vector<char> divc = {'M','D','C','L','X','V','I'};

        string ret;
        int t;

        for(int i=0; i<=div.size()/2; i++){
            t = num/div[i*2];
            if(t > 0){
                if(t < 4){
                    for(int j=0; j<num/div[i*2]; j++) 
                        ret += divc[i*2];
                } else if(t == 4) {
                    ret += divc[i*2];
                    ret += divc[i*2-1];
                } else if(t < 9){
                    ret += divc[i*2-1];
                    for(int j=0; j<(t-5);j++) ret += divc[i*2];
                } else if(t == 9) {
                    ret += divc[i*2];
                    ret += divc[i*2-2];
                }
            }
            
            num = num - div[i*2]*t;
        }
        return ret;
    }
};

int main(){
    Solution sl;
    cout<<sl.intToRoman(1994)<<endl;
}
