#include<bits/stdc++.h>

using namespace std;

int main(){

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T,n;
    string s1,s2;
    cin>>T;
    while(T--){
        cin>>n>>s1>>s2;
        int d1=0,d2=0,ret=0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]) d1++;
            if(s1[i] != s2[n-i-1]) d2++;
        }
        d2=max(d2,1);
		cout<<min(d1*2-1+(d1%2==0),d2*2-1+(d2%2==1))<<endl;
    }
    return 0;
}
