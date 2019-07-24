#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back

typedef long long ll;
using namespace std;


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {

        int n = books.size(), t, w;
        cout<<n<<endl;

        vector<int> dp(n + 1, (1<<30));
        dp[0] = 0;

        for(int i=1; i<=n; i++){
            for(int j=i; j>0; j--){
                w = 0;
                t = 0;
                for(int k=0; k<j; k++){
                    w += books[j - k][0];
                    if(t < books[j - k][1]) t = books[j - k][1];
                    if(w <= shelf_width);
                        dp[j] = min(dp[j - k], w) + t;
                }
                cout<<w<<" "<<t<<endl;
            }
            for(int j=0; j<=n; j++) cout<<dp[j]<<"\t";
            cout<<endl;
        }
        int ans = (1<<30);
        for(int i=0; i<n+1; i++)
            if(dp[i] < ans) ans = dp[i];
        
        return ans;
    }
};

int main(){

    Solution sl;
    vector<vector<int>> books;
    books.pb({1, 1});
    books.pb({2, 3});
    books.pb({2, 3});
    books.pb({1, 1});
    books.pb({1, 1});
    books.pb({1, 1});
    books.pb({1, 2});

    int shelf_width = 4;

    int ans = sl.minHeightShelves(books, shelf_width);
    cout<<ans<<endl;

    return 0;
}