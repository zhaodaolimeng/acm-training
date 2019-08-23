#include <iostream>

using namespace std;

bool check(int a){
    int t = 0;
    while(a>0){
        t += a % 10;
        a /= 10;
    }
    if(t%4 == 0) return true;
    return false;
}

int main(){
    int a;
    cin>>a;
    for(int i=0; i<10; i++){
        if(check(a+i)) {
            cout<<a+i<<endl;
            break;
        }
    }
    return 0;
}