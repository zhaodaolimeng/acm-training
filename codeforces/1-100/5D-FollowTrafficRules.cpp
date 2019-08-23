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


int main(){
    
    double a,v;
    double l,d,w;
    cin>>a>>v;
    cin>>l>>d>>w;
    
    double t1, t2, v_, vd;

    // 前半段
    if(v<=w){ // 最高车速小于限速
        if(2*d*a <= v*v) {
            t1 = sqrt(2.0*d/a);
            vd = sqrt(2.0*d*a);
        }else{
            t1 = v/a + (d-v*v*0.5/a)/v;
            vd = v;
        }
    }else if(2*d*a <= w*w){ // 标志之前没有到达限速
        t1 = sqrt(2.0*d/a);
        vd = sqrt(2.0*d*a);
    }else{
        v_ = sqrt(a*d+0.5*w*w);  // v_为前半段达到的最高速度
        if(v >= v_ && v_ >= w){  // 没有加满速之前开始降速通过标志
            t1 = (2.0*v_-w)/a;
        }else{  // 加满速之后降速通过标志
            t1 = v/a;  // 加速
            t1 += (d-(v*v-0.5*w*w)/a)/v;  // 满速
            t1 += (v-w)/a;  // 减速
        }
        vd = w;
    }

    // 后半段
    if(2.0*a*(l-d) <= v*v-vd*vd){  // 没加满速就到达了终点
        t2 = (sqrt(2.0*a*(l-d)+vd*vd)-vd)/a;
    }else{
        t2 = (v-vd)/a;
        t2 += ((l-d)-0.5*(v*v/a-vd*vd/a))/v;
    }

    // cout<<t1<<" "<<t2<<endl;

    cout<<fixed;
    cout<<setprecision(8)<<t1+t2<<endl;
    return 0;
}

/*
7143 4847
4193 2677 1991
1.00753 0.430567
*/