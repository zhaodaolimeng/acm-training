#include <iostream>
#include <vector>
using namespace std;


// class Solution{
// public:
//     string convert(string s, int numRows) {
//         if(numRows == 1)
//             return s;
//         string ss[numRows];
//         for (int i = 0; i < s.length(); ++i) {
//             int t = i % (2*numRows - 2);
//             if(t < numRows) ss[t] += s[i];
//             else ss[2*numRows - t - 2] += s[i];
//         }
//         string result;
//         for (int i = 0; i < numRows; ++i)
//             result += ss[i];
//         return result;
//     }
// };

class Solution {
public:
    string convert(string s, int n) {

        if(n == 1) return s;
        
        string ans;
        int seg_cnt = s.size() / (2*n-2) + (s.size()%(2*n-2) != 0);
        // int seg_cnt = s.size() / (2*n-2);
        int t;
        
        for(int i=0; i<n; i++){
            if(i == 0){
                for(int j=0; j<seg_cnt; j++){
                    t = j*(2*n-2);
                    if(t < s.size()) ans += s[t];
                }
            }else if(i == n-1){
                for(int j=0; j<seg_cnt; j++){
                    t = j*(2*n-2) + n - 1;
                    if(t < s.size()) ans += s[t];
                }
            }else{
                for(int j=0; j<seg_cnt; j++){
                    t = j*(2*n-2) + i;
                    if(t < s.size()) ans += s[t];
                    t = j*(2*n-2) + 2*n - 2 - i;
                    if(t < s.size()) ans += s[t];
                }
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};

int main() {

    Solution sl;

    // cout<<sl.convert("LEETCODEISHIRING", 3)<<endl;
    // cout<<sl.convert("LEETCODEISHIRING", 4)<<endl;
    // cout<<sl.convert("PAYPALISHIRING", 3)<<endl;
    // cout<<sl.convert("PAYPALISHIRING", 1)<<endl;

    cout<<sl.convert("PAYPALISHIRING", 7)<<endl;
    // cout<<sl.convert("P", 3)<<endl;

    return 0;
}