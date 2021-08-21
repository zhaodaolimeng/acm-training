#include <bits/stdc++.h>

using namespace std;

int arr[100000+1];
int l[100000], r[100000];

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n,lv=0,rv=0;

    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];
    
    for(int i=0; i<n; i++){
        lv += arr[i];
        l[i] = lv;
        rv += arr[n-1-i];
        r[n-1-i] = rv;
    }

    int ret = 0;
    for(int i=0; i<n-1; i++){
        ret += (l[i] == r[i+1])? 1:0;
    }
    cout<<ret<<endl;
    return 0;
}