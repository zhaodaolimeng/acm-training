#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int d;
    vector<int> abc(3);
    cin>>abc[0]>>abc[1]>>abc[2]>>d;

    sort(abc.begin(), abc.end());

    int d1 = abc[2] - abc[1], d2 = abc[1] - abc[0];
    if(d1 >= d && d2 >= d){
        cout<<0<<endl;
    }else{
        if(d1 < d && d2 < d){
            cout<<2*d - d1 - d2<<endl;
        }else{
            if(d2 < d){
                cout<<d - d2<<endl;
            }else{
                cout<<d - d1<<endl;
            }
        }
    }
    return 0;
}
