/**
 * 10C. Digital Root
 *
 * 可能要补充一些数论的基础知识了，看不太明白
 * http://www.cnblogs.com/qscqesze/p/5439079.html
 * http://www.cnblogs.com/zfyouxi/p/4877219.html
 */
#include<iostream>
#include<string.h>
using namespace std;

typedef long long LL;
LL ans[11];

int main()
{

    int n,i,j,tmp;

    scanf("%d",&n);

    LL anw = 0;

    for(i = 1;i <= n; ++i)
    {
        ans[(tmp = i%9) == 0 ? 9 : tmp]++;
        anw -= n/i;
    }

    for(i = 1;i <= 9; ++i)
        for(j = 1;j <= 9; ++j)
            anw += ans[i]*ans[j]*ans[(tmp = (i*j)%9) == 0 ? 9 : tmp];

    printf("%I64d\n",anw);

    return 0;
}

