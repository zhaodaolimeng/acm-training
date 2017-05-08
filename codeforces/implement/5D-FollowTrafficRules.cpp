#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>
#include <iomanip>
using namespace std;

// 5 70
// 200 170 40  

int main(){
    
    int a,v;
    int l,d,w;
    cin>>a>>v;
    cin>>l>>d>>w;
    
    double ret=0, v_;
    
    if(v<=w||2*d*a<=w*w){
        if(0.5*v*v/a>=l){
            ret = sqrt(2*l/a);
        }else{
            ret = 1.0*v/a;
            ret += (l-0.5*v*v/a)/v;
        }
    }else{
        if(2.0*a*d<=v*v){
            v_=sqrt(1.0*a*d+0.5*w*w);
            ret += (2.0*v_-w)/a;            
            if(0.5*(v*v-w*w)/a>=l-d){                
                ret += (sqrt(2*a*(l-d)+w*w)-w)/a;
            }else{
                ret += (1.0*v-w)/a;
                ret += 1.0*(l-d-0.5*(v*v-w*w)/a)/v + (1.0*v-w)/a;                
            }
        }else if(2.0*a*(l-d)>=1.0*w*w-v*v){
            ret += 1.0*w/a+v/a+(d-(v*v-0.5*w*w)/a)/v;
            ret += 1.0*(v-w)/a;
            ret += 1.0*(l-d-0.5*(v*v-w*w)/a)/v;            
        }else{
            ret += 1.0*(d-(v*v-w*w*0.5)/a)/v;
            ret += 1.0*v/a;
            ret += 1.0*(v-w)/a;
            ret += (sqrt(2.0*a*(l-d)+w*w)-w)/a;
        }
    }    
    cout<<fixed;
    cout<<setprecision(6)<<ret<<endl;
    //system("PAUSE");
    return 0;
}
