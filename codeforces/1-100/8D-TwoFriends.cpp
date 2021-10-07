/*
平面中有三个点a、b、c，有两条路径A、B，两端分别均固定在A和B上。
A必须从a出发通过b再到c，B需要从a出发直接到c.
其中路径A的长度最大是ab+bc+t1，B的长度最大是ac+t2。
问这两个路径的最大公共的长度可能是多少？（只有出发部分的共同长度计入，AB一旦分离之后的共同长度不计入）

将这两个路径想象成为两根棉线。
则以上问题转化成为了找到一个点p(x,y)，使得ac+t2-pc==ab+bc+t1-(pb+bc)最小

尝试使用迭代方式求解，但是似乎有多个极值点导致迭代失效

另一种方式是考虑到计算分叉点p是否在
这三个圆分别以a、b、c为圆心，半径在假设已知ap的情况下可通过限制条件求解出来
*/

#include<bits/stdc++.h>
using namespace std;

const double eps=1e-12;

#define point complex<double>

point a,b,c;
double ab,bc,ac,t1,t2;

void read(point &k){
    double x,y;
    cin >> x >> y;
    k=point(x,y);
}

// 三圆是否存在交点
bool intersect(point a,double Ra,point b,double Rb,point c,double Rc){
    if(abs(a-b)-(Ra+Rb)>eps) return false;
    if(abs(a-c)-Ra<eps && abs(b-c)-Rb<eps) return true;
    if(abs(a-b)+Ra-Rb<-eps || abs(a-b)+Rb-Ra<-eps) return false;
    
    // 对原图进行线性变换
    b-=a;c-=a;
    point i=point(b.real()/abs(b),b.imag()/abs(b));
    b/=i;c/=i;
    
    // 用勾股定理求交点
    double x=(Ra*Ra-Rb*Rb+abs(b)*abs(b))/(2*abs(b));
    double h=sqrt(max(Ra*Ra-x*x,0.0));

    // 对上下两个交点都进行判断
    if(abs(point(x,h)-c)-Rc<eps || abs(point(x,-h)-c)-Rc<eps) return true;
    return false;
}

// 查看两两的交点是否在第三圆内
bool eval(point a,double Ra,point b,double Rb,point c,double Rc){
    if(Ra<eps || Rb<eps || Rc<eps) return false;
    if(intersect(a,Ra,b,Rb,c,Rc)) return true;
    if(intersect(a,Ra,c,Rc,b,Rb)) return true;
    if(intersect(b,Rb,c,Rc,a,Ra)) return true;
    return false;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(20);
    
    cin >> t1 >> t2;
    read(a);read(c);read(b);
    ac=abs(a-c);ab=abs(a-b);bc=abs(b-c);
    
    t1+=ab+bc;
    t2+=ac;

    // 全程陪同
    if(t2-(ab+bc)>-eps){
        cout<<min(t1,t2)<<endl;
        return 0;
    }
        
    
    double l=0,r=min(t1,t2); // 陪同路程的上下界
    while(fabs(r-l)>eps) {
        double m=(r+l)*.5;
        if(eval(a,m,b,t1-bc-m,c,t2-m)) l=m; // 存在交点则扩大m
        else r=m;
    }
    cout << (r+l)*.5<<endl;
    return 0;
}
