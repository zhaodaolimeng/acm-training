#include <bits/stdc++.h>

using namespace std;

int arr[150010];

int main(){

    int t, n;
    cin>>t;
    while(t--){
        int cnt = 0;
        cin>>n;
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);

        int minn = arr[n-1];
        for(int i=n-2; i>=0; i--){
            if(arr[i] > minn) cnt++; 
            else minn = arr[i];
        }
        cout<<cnt<<endl;
    }

}