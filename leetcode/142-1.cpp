#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        
        int n = count.size(), minn, maxn;
        
        vector<double> ret;
        if(n == 0) {
            vector<double> ret(5, 0.0);
            return ret;
        }
        
        for(int i=0; i<n; i++)
            if(count[i]!=0){
                minn = i;
                break;
            }
        ret.push_back(minn);
        for(int i=n-1; i>=0; i--)
            if(count[i]!=0){
                maxn = i;
                break;
            }
        ret.push_back(maxn);
        int ncnt = 0, mostn=0, maxcnt=0;
        double sum = 0.0;
        for(int i=0; i<n; i++) {
            if(count[i] == 0) continue;
            sum += count[i]*i;
            ncnt += count[i];
            if(count[i]>maxcnt){
                mostn = i;
                maxcnt = count[i];
            }
        }
        ret.push_back(sum/(1.0*ncnt));

        cout<<sum<<" "<<ncnt<<endl;
        

        if(ncnt%2 == 0){
            int i1=ncnt/2, i2=ncnt/2-1, a, b, ncnt=0;
            cout<<i1<<" "<<i2<<endl;
            for(int i=0; i<n; i++){
                if(i1 >= ncnt && i1 < ncnt + count[i]) a=i;
                if(i2 >= ncnt && i2 < ncnt + count[i]) b=i;
                ncnt += count[i];
            }
            cout<<a<<" "<<b<<endl;
            ret.push_back(1.0*(a+b)/2);
        }else{
            int i0=ncnt/2, a;
            for(int i=0; i<n; i++){
                if(i0 >= ncnt && i0 < ncnt + count[i]) a=i0;
            }
            ret.push_back(1.0*a);
        }
        ret.push_back(1.0*mostn);
        return ret;
    }
};

int main(){

    vector<int>count = {0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    Solution sl;
    sl.sampleStats(count);


}