/**
 * codeforces 12C
 * ==============
 */
#include <iostream>
#include <stdlib.h>
#include <map>
#include <algorithm>
using namespace std;

int prices[101];
int fruits[101];

int main() {

    int n,m;
    cin>>n>>m;
    string str;
    map<string, int> cmap;

    for (int i = 0; i < n; ++i) cin>>prices[i];

    for (int i = 0; i < m; ++i) {
        cin>>str;
        if(cmap.find(str)==cmap.end())
            cmap[str] = 1;
        else
            cmap[str] += 1;
    }

    int flag = 0;
    map<string, int>::iterator it;
    for (it = cmap.begin(); it != cmap.end(); it++){
        fruits[flag] = it->second;
        flag ++;
    }
    sort(prices, prices + n);
    sort(fruits, fruits + m);

    int a=0, b=0;
    for(int i=0;i<m; i++){
        a += fruits[i] * prices[m-1-i];
        b += fruits[m-i-1] * prices[n-1-i];
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
