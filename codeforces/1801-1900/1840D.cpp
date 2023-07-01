#include<bits/stdc++.h>

/*
def f(m):
	c, l = 0, 0
	for i in range(n):
		if a[i]-a[l]>2*m:
			c+=1
			l=i
	return c<3

for i in range(int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	a.sort()
	l, r = 0, 10**9
	while l<r:
		mid=(l+r)>>1
		if not f(mid): l=mid+1
		else: r=mid
	print(l)

# 原理是搜索最远边界
*/

using namespace std;


// 读错题目了。。。

int get_wait_time(int start,int end,vector<int>&arr,vector<int>&pre){

    int ret = 0;
    double target = pre[end]/(end-start+1);
    int l=start, r=end, mid;
    while(l<r){
        mid = (l+r)/2;
        if(arr[mid]<=target && arr[mid+1]>=target) break;
        else if(arr[mid]<target) l = mid;
        else r = mid;
    }
    if(target-arr[mid] > arr[mid+1]-target) mid+=1;
    ret = (arr[mid]*(mid-start+1) - pre[mid]);
    if(mid+1<end) ret += (pre[end] - pre[mid+1] - arr[mid]*(end-mid));
    return ret;
}

int main(){
    int t,n,a,b,x1,x2;
    
    std::cin>>t;

    while (t--){
        std::cin>>n;

        vector<int> arr(n,0);
        vector<int> pre(n,0);

        int ret=(1<<30), maxd=0;
        
        for(int i=0;i<n;i++) {
            std::cin>>arr[i];
            if(i > 0) pre[i] = pre[i-1] + arr[i];
        }

        std::sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++)
            if(i > 0) pre[i] = pre[i-1] + arr[i];

        for(int x1=0;x1<n-2;x1++){
            maxd = get_wait_time(0,x1,arr,pre);
            for(int x2=x1+1;x2<n-1;x2++){
                maxd += get_wait_time(x1+1,x2,arr,pre);
                maxd += get_wait_time(x2+1,n-1,arr,pre);
                if(maxd < ret) ret = maxd;
            }
        }

        std::cout<<ret<<endl;
    }
    return 0;
}
