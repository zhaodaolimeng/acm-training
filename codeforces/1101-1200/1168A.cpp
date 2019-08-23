#include <bits/stdc++.h>

using namespace std;

int n, m, t;
vector<int> a;

bool check(int x){
    int last = a[0];
    if(a[0] + x >= m) last = 0;
    for(int i=1; i<n; i++){
        if(last > a[i] + x) return false;
        if(a[i] <= last) t = last;
        else if(a[i] + x >= m && a[i] + x - m >= last) t = last;
        else t = a[i];
        last = t;
    }
    return true;
}

int main(){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>t;
        a.push_back(t);
    }

    int l = 0, r = m+1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout<<l<<endl;
    return 0;
}
