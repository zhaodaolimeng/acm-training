#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<algorithm>
#include<numeric>

using namespace std;
using pii=pair<int,int>;

/*
使用deque
同时使用set存储元素
*/

struct DSU {
    std::vector<size_t> pa, size, vis;

    explicit DSU(size_t size_) : pa(size_), size(size_, 1), vis(size_, 0) {
        std::iota(pa.begin(), pa.end(), 0);
    }

    size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
    
    void unite(size_t x, size_t y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) std::swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }
};

int n,k,a,t;

int main(){
    // ifstream std::cin("input.txt");
    // ofstream std::cout("output.txt");

    deque<int> d;
    set<int> s;
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        if(d.size()<k) {
            if(s.find(a)==s.end()){
                d.push_front(a);
                s.insert(a);
            }
        } else if(d.size()==k) {
            if(s.find(a)==s.end()){
                t = d.back();
                d.pop_back();
                d.push_front(a);
                s.erase(t);
                s.insert(a);
            }
        }
    }
    
    cout<<d.size()<<endl;
    for(int t : d){
        cout<<t<<" ";
    }
    cout<<endl;
    
    return 0;
}