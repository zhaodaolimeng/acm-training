#include<bits/stdc++.h>
using namespace std;

int t,n,k,a[200005],i,x,minx;

int main(){
	scanf("%d",&t);

	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1; i<=n; i++) scanf("%d", &a[i]);
		for(x=minx=1; x+k<=n; x++)
            if(a[x+k]-a[x] < a[minx+k]-a[minx])
                minx=x;
		printf("%d\n", (a[minx]+a[minx+k])>>1);
	}
	return 0;
}
