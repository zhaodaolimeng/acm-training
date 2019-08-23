#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n, a, m0, m1, m2, m, ret;

    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        m0=m1=m2=0;
        for(int j=0; j<n; j++) {
            cin>>a;
            m = a%3;
            if(m == 0) m0 ++;
            else if(m == 1) m1 ++;
            else m2 ++;
        }
        if(m2 < m1){
            ret = m0 + m2 + (m1 - m2)/3;
        }else if (m2 > m1){
            ret = m0 + m1 + (m2 - m1)/3;
        } else{
            ret = m0 + m1;
        }
        cout<<ret<<endl;
    }
}
