#include <iostream>

using namespace std;


// const int MAXN = 1000005;
// char s1[MAXN], s2[MAXN];

int main(){

    string s1, s2;
    int n, p1, p2, cnt1, cnt2;
    cin>>n;

    while(n--){
        cin>>s1>>s2;
        bool ok = true;
        for(p1= p2 = 0; p1 < s1.size() && p2 < s2.size(); p1++, p2++){
            if(s1[p1] == s2[p2]){
                cnt1 = cnt2 = 0;
                while(p1 < s1.size() - 1 && s1[p1] == s1[p1+1]){
                    cnt1 ++;
                    p1 ++;
                }
                while(p2 < s2.size() - 1 && s2[p2] == s2[p2+1]){
                    cnt2++;
                    p2 ++;
                }
                if(cnt1 > cnt2) {
                    ok = false;
                    break;
                }
            }else{
                ok = false;
                break;
            }
        }
        if(p1 != s1.size() || p2 != s2.size()) ok = false;
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}