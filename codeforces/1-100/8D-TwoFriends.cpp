/**
 * 平面中有三个点a、b、c，有两条路径A、B，两端分别均固定在A和B上。
 * A必须从a出发通过b再到c，B需要从a出发直接到c.
 * 其中路径A的长度最大是ab+bc+t1，B的长度最大是ac+t2。
 * 问这两个路径的最大公共的长度可能是多少？（只有出发部分的共同长度计入，AB一旦分离之后的共同长度不计入）
 *
 * 将这两个路径想象成为两根棉线。
 * 则以上问题转化成为了找到一个点p(x,y)，使得ac+t2-pc==ab+bc+t1-(pb+bc)最小，梯度下降？
 *
 * 他人统一的解法是将上式展开为三个约束，通过计算三个约束的半径长度得到
 * http://blog.csdn.net/popoqqq/article/details/45719007
 *
 */
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

struct point{
    double x;
    double y;
};

double dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main(){

    int t1,t2;
    point a, b, c, p;

    cin>>t1>>t2;
    cin>>a.x>>a.y>>c.x>>c.y>>b.x>>b.y;

    double must_A = dist(a, c);
    double must_B = dist(a, b) + dist(b, c);

    p.x = a.x;
    p.y = a.y;

    must_A - dist(p, b) - dist(b, c);
    must_B - dist(p, c);



    return 0;
}

