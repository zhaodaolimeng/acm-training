#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int state = 0, next;

        for(int i=0; i<s.size(); i++){
            next = s[i];
            if(state == 0){
                if(next == ' ') state = 0;
                else if(next == '+' || next == '-') state = 1;
                else if(next == '0') state = 2;
                else if(next <= '9' && next >= '1') state = 3;
                else if(next == '.') state = 42;
                else return false;
            }else if(state == 1){
                if(next == '0') state = 2;
                else if(next == '.') state = 42;
                else if(next <='9' && next >= '1') state = 3;
                else return false;
            }else if(state == 2){
                if(next == ' ') state = 9;
                else if(next <= '9' && next >= '0') state = 2;
                else if(next == '.') state = 4;
                else if(next == 'e') state = 6;
                else return false;
            }else if(state == 3){
                if(next == ' ') state = 9;
                else if(next == '.') state = 4;
                else if(next == 'e') state = 6;
                else if(next <= '9' && next >= '0') state = 3;
                else return false;
            }else if(state == 4){
                if(next == ' ') state = 9;
                else if(next == 'e') state = 6;
                else if(next <= '9' && next >= '0') state = 5;
                else return false;
            }else if(state == 42){
                if(next <= '9' && next >= '0') state = 5;
                else return false;
            }else if(state == 5){
                if(next == ' ') state = 9;
                else if(next == 'e') state = 6;
                else if(next <= '9' && next >= '0') state = 5;
                else return false;
            }else if(state == 6){
                if(next == '+' || next == '-') state = 7;
                else if(next <= '9' && next >= '0') state = 8;
                else return false;
            }else if(state == 7){
                if(next <= '9' && next >= '1') state = 8;
                else return false;
            }else if (state == 8){
                if(next == ' ') state = 9;
                else if(next <= '9' && next >= '0') state = 8;
                else return false;
            }else if(state == 9){
                if(next == ' ') state = 9;
                else return false;
            }
            cout<<state<<endl;
        }
        if(state == 0 || state == 1 || state == 42 ||
            state == 6 || state == 7) 
            return false;
        return true;
    }
};

int main(){
    Solution sl;
    // bool ret = sl.isNumber(" 0.1 ");
    // bool ret = sl.isNumber("+53.5e93");
    // bool ret = sl.isNumber("01");
    bool ret = sl.isNumber(" -.7e+0435");
    cout<<ret<<endl;
}