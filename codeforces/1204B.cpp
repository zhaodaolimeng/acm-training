#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l, r;
    cin>>n>>l>>r;

    int min_ans = (n-l);
    min_ans += (1<<l)-1;

    int max_ans = (1<<r)-1;
    max_ans += (1<<(r-1))*(n-r);

    cout<<min_ans<<" "<<max_ans<<endl;
}