#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string ss[numRows];
        for (int i = 0; i < s.length(); ++i) {
            int t = i % (2*numRows - 2);
            if(t < numRows) ss[t] += s[i];
            else ss[2*numRows - t - 2] += s[i];
        }
        string result;
        for (int i = 0; i < numRows; ++i)
            result += ss[i];
        return result;
    }
};

int main() {

    Solution sl;

//    cout<<sl.convert("PAYPALISHIRING", 3)<<endl;
//    cout<<sl.convert("PAYPALISHIRING", 1)<<endl;
    cout<<sl.convert("P", 3)<<endl;

    return 0;
}