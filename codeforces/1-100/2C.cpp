// 平面中有三个圆，求一点看到这三个圆的大小是一样的
// 即该点到这三个圆的距离与三个圆的半径比例一致
// 如果能说明损失是凸的，一种方法是迭代搜索结果

#include<bits/stdc++.h>

using namespace std;

double x[3],y[3],r[3],k[3];
// k*r0 = sqrt((x-x0)^2+(y-y0)^2)

// f为当前位置为x0,y0时的损失
double f(double x0, double y0){
    double ret = 0;
    for(int i=0;i<3;i++) k[i] = sqrt((x0-x[i])*(x0-x[i])+(y0-y[i])*(y0-y[i]))/r[i];
    for(int i=0;i<3;i++) ret += (k[i]-k[(i+1)%3])*(k[i]-k[(i+1)%3]);
    return ret;
}

int main(){

    for(int i=0;i<3;i++) cin>>x[i]>>y[i]>>r[i];
    double x0 = (x[0]+x[1]+x[2])/3, y0 = (y[0]+y[1]+y[2])/3;
    for(double step=1;step>1e-6;){
        if(f(x0,y0)>f(x0-step,y0)) x0 -= step;
        else if(f(x0,y0)>f(x0+step,y0)) x0 += step;
        else if(f(x0,y0)>f(x0,y0-step)) y0 -= step;
        else if(f(x0,y0)>f(x0,y0+step)) y0 += step;
        else step*=0.7;
    }
    if(f(x0,y0) < 1e-5) cout<<fixed<<setprecision(5)<<x0<<" "<<y0<<endl;
    return 0;
}
