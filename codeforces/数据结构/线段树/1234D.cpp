#include <algorithm>
#include <iostream>
#include <vector>

// Segment tree.
class SegmentTree {
    int n;
    std::vector<long long> sum;

    public:
    SegmentTree(int _n, std::string s) {
        for (n = 1; n < _n; n <<= 1);
        sum.resize(n << 1);
        std::fill(sum.begin(),sum.end(),0);
        // std::copy(vec.begin(), vec.end(), sum.begin() + n);
        // for(const auto & v: sum) std::cout<<v<<' ';
        // std::cout<<'\n';
        // std::cout<<n<<'\n';
        
        for(int i = 0; i < _n; i++)
            sum[i+n] = (1<<(s[i]-'a'));
        
        for (int i = n - 1; i; --i) 
            sum[i] = sum[i << 1] | sum[(i << 1) | 1];
        
        // for(const auto & v: sum) std::cout<<v<<' ';
        // std::cout<<'\n';
    }

    void modify(int x, int v) {

        // std::cout<<"begin modify\n";
        
        for (x+=n; x; x >>= 1) {
            if(x>=n){
                sum[x] = (1<<(v-'a'));
            } else {
                sum[x] = sum[x<<1] | sum[(x<<1)|1];
            }
            // for(const auto & v: sum) std::cout<<v<<' ';
            // std::cout<<'\n';
        }

        // std::cout<<"end modify\n";
    }

    long long query(int l, int r) {
        l += n, r += n;
        long long res = 0;
        for (int ll = l, rr = r; ll <= rr; ll >>= 1, rr >>= 1) {
            if (ll & 1) res |= sum[ll++];
            if (~rr & 1) res |= sum[rr--];
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = s.length(), q;
    std::cin >> q;

    SegmentTree seg(n, s);

    for (; q; --q) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int p;
            char x;
            std::cin >> p >> x;
            seg.modify(p-1, x);
        } else if (op == 2) {
            int l, r, t, cnt=0;
            std::cin >> l >> r;
            t = seg.query(l-1, r-1);
            // std::cout<<"t="<< t << '\n';

            for(;t>0;t>>=1) if((t&1)==1) cnt++;
            // std::cout<<"cnt="<< cnt << '\n';
            std::cout<< cnt << '\n';
        }
    }
    return 0;
}