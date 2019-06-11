/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        int res=0, a, b, t;
        vector<char> ret_single_mult;
        string ret = "0";
        for(int i=0; i<num1.size(); i++){
            ret_single_mult.clear();
            res = 0;
            a = num1[i] - '0';
            if(a != 0){
                for(int j=num2.size()-1; j>=0; j--){
                    b = num2[j] - '0';
                    t = a*b + res;
                    ret_single_mult.push_back(t%10 + '0');
                    res = t / 10;
                }
                if(res != 0) ret_single_mult.push_back(res + '0');
            }else
                ret_single_mult.push_back('0');
            string s = reverse_concat(ret_single_mult);
            // cout<<ret<<' '<<s<<endl;
            if(ret != "0") ret += "0";
            ret = add(ret, s);
        }
        return ret;
    }

    string add(string num1, string num2){
        int nlen_long = max(num1.size(), num2.size());
        int res=0, a, b, t;
        vector<char> ret;
        for(int i=0; i<nlen_long; i++){
            t = num1.size() - i - 1;
            a = t>=0? num1[t] - '0' : 0; 
            t = num2.size() - i - 1;
            b = t>=0? num2[t] - '0' : 0; 
            t = a + b + res;
            // cout<<a<<' '<<b<<' '<<res<<' '<<endl;
            if(t>=10){
                res = 1;
                ret.push_back(t - 10 + '0');
            }else{
                ret.push_back(t + '0');
                res = 0;
            }
        }
        if(res == 1) ret.push_back('1');
        return reverse_concat(ret);
    }

    string reverse_concat(vector<char>& vc){
        reverse(vc.begin(), vc.end());
        string ret_s;
        for(auto const& c : vc) ret_s += c;
        return ret_s;
    }
};

int main(){
    Solution sl;
    // string ret = sl.add("0", "1");
    // cout<<ret<<endl;

    string ret = sl.multiply("12", "12");
    cout<<ret<<endl;
}
