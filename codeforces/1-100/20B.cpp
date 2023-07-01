#include<bits/stdc++.h>

// 练习一下高精度搜索
// -b/(2*a)

using namespace std;

const int inf = (1<<31);
const double eps = 1e-6;

int main(){

    int a,b,c;
    std::cin>>a>>b>>c;

    int p = -b/(2*a);
    int l,r,x,t;

    if(c == p){
        std::cout<<1<<endl;
        std::cout<<c<<endl;
    }else if(c > p){
        std::cout<<0<<endl;
    }else{
        std::cout<<2<<endl;

        // -inf,p p,inf
        l = -inf, r = p;

        while(l<r){
            x = (l+r)/2;
            t = a*x*x+b*x+c;
            if(abs(t)<=eps){
                break;
            }else if(t>eps){
                r = x;
            }else{
                l = x;
            }
        }
        std::cout<<x<<endl;

        l = p, r = inf;

        while(l<r){
            x = (l+r)/2;
            t = a*x*x+b*x+c;
            if(abs(t)<=eps){
                break;
            }else if(t>eps){
                r = x;
            }else{
                l = x;
            }
        }
        std::cout<<x<<endl;
    }
    return 0;
}