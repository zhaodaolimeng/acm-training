#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<numeric>

using namespace std;
using pii=pair<int,int>;

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

int n;

int main(){
    // ifstream std::cin("input.txt");
    // ofstream std::cout("output.txt");
    
    cin>>n;
    DSU dsu(n + 1);

    // cout<<"-----"<<endl;

    // for(int i=1;i<=n;i++){
    //     cin>>a>>b;
    //     dsu.unite(a,1000+b);
    // }

    vector<pii> v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i].first>>v[i].second;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(v[i].first==v[j].first||v[i].second==v[j].second){
                dsu.unite(i,j);
            }
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(dsu.find(i));
    cout<<s.size()-1<<endl;
    
    return 0;
}