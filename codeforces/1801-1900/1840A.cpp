#include<bits/stdc++.h>

using namespace std;

int main(){

    int t,n,a;
    string input;
    string output;
    

    std::cin>>t;
    while(t--){
        std::cin>>n>>input;
        output = "";
        for(int i=0;i<input.size();i++){
            for(int j=i+1;j<input.size();j++){
                if(input[j]==input[i]){
                    a = j;
                    break;
                }
            }
            output += input[i];
            i = a;
        }
        std::cout<<output<<endl;
    }
    return 0;
}

