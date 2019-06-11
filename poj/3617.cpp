// poj 3617

#include <iostream>
#include <stdio.h>
using namespace std;

int N;
char s[2001], t[2001];

int main() {

    cin>>N;
    for(int i=0;i<N;i++) cin>>s[i];
    int head=0, tail=N-1, i=0;

    while(head<=tail){
        if(s[head] > s[tail]){
            t[i++] += s[tail--];
        }else if(s[head] < s[tail]){
            t[i++] += s[head++];
        }else{
            int head0 = head, tail0 = tail;
            while(head0 < tail0 && s[head0] == s[tail0]){
                head0 ++;
                tail0 --;
            }
            if(head0 >= tail0){
                t[i++] += s[head++];
            }else{
                if(s[head0] > s[tail0]){
                    t[i++] += s[tail--];
                } else
                    t[i++] += s[head++];
            }
        }
    }
    for(int i=0;i<N;i++){
        if(i != 0 && i%80 == 0) putchar('\n');
        putchar(t[i]);
    }

    return 0;
}

/*
6
A
C
D
B
C
B
 */