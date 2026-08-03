#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

struct DSU {
    std::vector<size_t> pa, size;

    explicit DSU(size_t size_) : pa(size_), size(size_, 1) {
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

int n,m,k,a,b;

int main(){
    // ifstream std::cin("input.txt");
    // ofstream std::cout("output.txt");
    
    cin>>n>>m;
    DSU dsu(n + 1);

    // cout<<"-----"<<endl;

    for(int i=1;i<=m;i++){
        cin>>k;
        a = -1;
        for(int j=0;j<k;j++){
            cin>>b;
            if(a==-1){
                a = b;
            }else{
                // cout<<i<<" "<<j<<" "<<b<<endl;
                dsu.unite(a,b);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     if(i>1)cout<<" ";
    //     cout<<dsu.size[i];
    // }
    // cout<<endl;
    // cout<<"-----"<<endl;

    // for(int i=1;i<=n;i++){
    //     if(i>1)cout<<" ";
    //     cout<<dsu.pa[i];
    // }
    // cout<<endl;
    // cout<<"-----"<<endl;

    for(int i=1;i<=n;i++){
        if(i>1)cout<<" ";
        cout<<dsu.size[dsu.find(i)];
    }
    cout<<endl;

    
    return 0;
}