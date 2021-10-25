/*
一组元素，每个元素具有三类属性。
找到所有元素A，满足存在一个元素B的三类属性都比A的要高，输出A的个数。
使用一类属性进行排序之后，问题变成找到满足A右侧存在元素所有属性都比A高的元素个数。
从右向左遍历，维持一个结构，使得结构中
*/

#include<bits/stdc++.h>
using namespace std;

map<int,int> M;

class Lady {
public:
    int b, i, r;
    bool operator <(const Lady &l) const {
        return b!=l.b? b<l.b: i!=l.i? i>l.i: r<l.r;
    }
};

int main(){

    ios::sync_with_stdio(false);
    int n,ans=0;
    cin>>n;
    vector<Lady> ladies(n);
    map<int,int> M;  // r足够大的元素，key为该元素对应的i
    M[-INT_MAX/2] = INT_MAX/2; M[INT_MAX/2] = -INT_MAX/2;
    
    for(int i=0;i<n;i++) cin>>ladies[i].b;
    for(int i=0;i<n;i++) cin>>ladies[i].i;
    for(int i=0;i<n;i++) cin>>ladies[i].r;

    sort(ladies.begin(),ladies.end());

    // 从右向左遍历，维护一个“key等于i具有的最大r”的数据结构
    for(int i=n-1; i>=0; i--) {
        map<int,int>::iterator it = M.upper_bound(ladies[i].i);
        if(ladies[i].r < it->second){
            ans++;
        }else if(ladies[i].r > M[ladies[i].i]){
            M[ladies[i].i] = ladies[i].r;
            for(it=--M.lower_bound(ladies[i].i);ladies[i].r>it->second;)
                M.erase(it--);
        }
    }
    cout<<ans<<endl;
    return 0;
}
