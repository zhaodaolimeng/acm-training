#include<bits/stdc++.h>

using namespace std;

int main(){
    int T,t;
    string sa,sb;
    
    cin>>T;
    while(T--){

        cin>>t>>t;
        cin>>sa>>sb;
        reverse(sb.begin(),sb.end());
        sa += sb;
        
        int same = 0;
        for(int i=0;i<sa.size()-1;i++){
            if(sa[i]==sa[i+1]) same++;
        }

        if(same <= 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
