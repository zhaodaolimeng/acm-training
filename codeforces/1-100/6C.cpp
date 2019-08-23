#include <stdio.h>
#include <iostream>
 
using namespace std;
 
int bars[100010];
int n;
 
int main(int argc, char ** args){
    
    cin>>n;
    for (int i=0; i<n; i++) cin>>bars[i];

    int p0 = 0, p1 = n-1, A = 0, B = 0;

    while(p0 != p1){
        if(A > B){
            B += bars[p1];
            p1 --;
        }else{
            A += bars[p0];
            p0 ++;
        }
    }
    int a_eat = p0;
    int b_eat = n-p1-1;
    if(A > B) b_eat ++;
    else a_eat ++;
    
    cout<<a_eat<<" "<<b_eat<<endl;
    return 0;
}