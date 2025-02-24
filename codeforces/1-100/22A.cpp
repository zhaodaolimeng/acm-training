#include<iostream>
#include<string>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n,t,mint,mins;
    cin>>n;

    n--;
    cin>>mint;
    mins = mint;

    while(n--){
        cin>>t;
        if(t<mint){
            mins = mint;
            mint = t;
        }else if (t>mint && (t<mins || mint==mins)){
            mins = t;
        }
    }
    if(mins == mint) cout<<"NO"<<endl;
    else cout<<mins<<endl;
    return 0;
}
