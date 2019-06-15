#include <map>
#include <vector>
#include <iostream>

using namespace std;


int main(){

    int n, t;
    int arr[] = {4, 8, 15, 16, 23, 42};
    vector<int> dp(7, 0);

    int maxv = 0;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        if(t == 42 && dp[6] > 0) dp[6] --, maxv ++;
        else if(t == 23 && dp[5] > 0) dp[5] --, dp[6] ++;
        else if(t == 16 && dp[4] > 0) dp[4] --, dp[5] ++;
        else if(t == 15 && dp[3] > 0) dp[3] --, dp[4] ++;
        else if(t == 8 && dp[2] > 0) dp[2] --, dp[3] ++;
        else if(t == 4) dp[2] ++;

        // cout<<t;
        // for(int j : dp) cout<<"\t"<<j;
        // cout<<endl;
    }
    if(n < maxv*6) cout<<0<<endl;
    else cout<<n - maxv*6<<endl;
    return 0;
}
