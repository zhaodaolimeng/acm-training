#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    vector<int> a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        a.push_back(abs(t));
    }
    sort(a.begin(), a.end());

    int ret = 0, l=0, r=0;
    for(int i = 1, j = 0; i < n; ++i) {
        while(j < i && a[j] * 2 < a[i]) ++j;
        ret += i - j;
    }

    // for (int i=0;i<n;++i) {
	// 	ret += a+i-lower_bound(a, a+a.size(), (a[i]+1)/2);
	// }

    cout<<ret<<endl;
    return 0;
}