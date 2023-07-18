#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    string a;
    string b;

    cin>>T;
    while(T--){
        cin>>a>>b;

        if(a.size()<b.size()){
            cout<<(int)(b[0]-'0') + (b.size()-1)*9<<endl;
        }else{
            bool hit = false;
            for(int i=0;i<a.size();i++){
                if(a[i] < b[i]){
                    cout<<(int)(b[i]-a[i]) + (a.size()-i-1)*9<<endl;
                    hit = true;
                    break;
                }
            }
            if(!hit){
                cout<<0<<endl;
            }
        }
    }
    return 0;
}