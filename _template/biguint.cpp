#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<ctime>
#include<iomanip>
#include<fstream>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
typedef long long LL;
#define sz(a) int((a).size())
#define pb push_back
const int INF = 2147483647;
const double PI = 3.141592653589793;

namespace arith {

    typedef unsigned int uint;
    typedef unsigned long long ull;

    const int LOGBASE = sizeof(uint)*8;
    const ull BASE = 1ULL<<LOGBASE;

    inline void assert_msg(bool cond, const std::string& msg) {
        if (!cond) { std::cerr << "arith: " << msg << std::endl; exit(1); }
    }

    inline void strip(std::vector<uint>& r, int pos=0) {
        while (r.size()>pos && !r.back()) r.pop_back();
    }

    inline void add(const std::vector<uint>& x, ull s, std::vector<uint>& r) {
        r.resize(x.size());
        for (int i=0; i<x.size(); ++i) { s += x[i]; r[i] = s; s >>= LOGBASE; }
        if (s) r.push_back(s);
    }

    inline void add(const std::vector<uint>& x, const std::vector<uint>& y, std::vector<uint>& r) {
        r.resize(std::max(x.size(), y.size())); ull s=0; int i=0;
        for (; i<x.size() && i<y.size(); ++i) { s += x[i]; s += y[i]; r[i] = s; s >>= LOGBASE; }
        for (; i<x.size(); ++i) { s += x[i]; r[i] = s; s >>= LOGBASE; }
        for (; i<y.size(); ++i) { s += y[i]; r[i] = s; s >>= LOGBASE; }
        if (s) r.push_back(s);
    }

    template<class Iter1, class Iter2>
    inline int cmp(Iter1 b1, Iter2 e1, Iter1 b2, Iter2 e2) {
        if (e1-b1!=e2-b2) return e1-b1<e2-b2 ? -1 : 1;
        while (e1!=b1) if (*--e1 != *--e2) return *e1<*e2 ? -1 : 1;
        return 0;
    }

    inline void sub(const std::vector<uint>& x, const std::vector<uint>& y, std::vector<uint>& r, int pos=0) {
        int old_pos=pos; r.resize(x.size()); ull s=1;
        for (int i=0; i<y.size(); ++i, ++pos) { s += x[pos]; s += (BASE-1)-y[i]; r[pos] = s; s >>= LOGBASE; }
        if (!s) {
            for (; !x[pos]; ++pos) r[pos] = BASE-1;
            r[pos] = x[pos]-1; ++pos;
        }
        for (; pos<x.size(); ++pos) r[pos] = x[pos];
        strip(r, old_pos);
    }

    inline void mul(const std::vector<uint>& x, uint v, std::vector<uint>& r) {
        r.resize(x.size()); ull s=0;
        for (int i=0; i<x.size(); ++i) { s += 1ULL*v*x[i]; r[i] = s; s >>= LOGBASE; }
        if (s) r.push_back(s);
        strip(r);
    }

    inline void muladd(const std::vector<uint>& x, uint v, std::vector<uint>& r, int pos) {
        ull s=0;
        for (int i=0; i<x.size(); ++i, ++pos) { s += 1ULL*v*x[i] + r[pos]; r[pos] = s; s >>= LOGBASE; }
        for (; s && pos<r.size(); ++pos) { s += r[pos]; r[pos] = s; s >>= LOGBASE; }
        if (s) r.push_back(s);
    }

    inline void mul(const std::vector<uint>& x, const std::vector<uint>& y, std::vector<uint>& r) {
        if (x.empty() || y.empty()) return;
        r.resize(x.size()+y.size()-1);
        for (int i=x.size()-1; i>=0; --i) muladd(y, x[i], r, i);
        strip(r);
    }

    inline uint div(const std::vector<uint>& x, uint d, std::vector<uint>& r) {
        r.resize(x.size()); uint q=0;
        for (int i=x.size()-1; i>=0; --i) { ull t = BASE*q + x[i]; r[i] = t/d; q = t%d; }
        strip(r);
        return q;
    }

    inline void div(std::vector<uint>& x, const std::vector<uint>& y, std::vector<uint>& r) {
        if (x.size()<y.size()) return;
        int pos = x.size()-y.size(); r.resize(pos+1);
        std::vector<uint> buf;
        do {
            uint q=0;
            for (uint m=1U<<LOGBASE-1; m; m>>=1) {
                mul(y, q|m, buf);
                if (cmp(buf.begin(), buf.end(), x.begin()+pos, x.end()) <= 0) q|=m;
            }
            r[pos] = q; mul(y, q, buf);
            sub(x, buf, x, pos);
        } while (pos--);
        strip(r);
    }

    inline void bit_and(const std::vector<uint>& x, const std::vector<uint>& y, std::vector<uint>& r) {
        r.resize(std::min(x.size(), y.size()));
        for (int i=0; i<r.size(); ++i) r[i] = x[i]&y[i];
        strip(r);
    }

    inline void bit_or(const std::vector<uint>& x, const std::vector<uint>& y, std::vector<uint>& r) {
        r.resize(std::max(x.size(), y.size())); int i=0;
        for (; i<x.size() && i<y.size(); ++i) r[i] = x[i]|y[i];
        for (; i<x.size(); ++i) r[i] = x[i];
        for (; i<y.size(); ++i) r[i] = y[i];
    }

    inline void bit_xor(const std::vector<uint>& x, const std::vector<uint>& y, std::vector<uint>& r) {
        r.resize(std::max(x.size(), y.size())); int i=0;
        for (; i<x.size() && i<y.size(); ++i) r[i] = x[i]^y[i];
        for (; i<x.size(); ++i) r[i] = x[i];
        for (; i<y.size(); ++i) r[i] = y[i];
        strip(r);
    }

    inline void bit_neg(const std::vector<uint>& x, std::vector<uint>& r) {
        r.resize(x.size());
        for (int i=0; i<x.size(); ++i) r[i] = ~x[i];
        strip(r);
    }

    inline void bit_shr(const std::vector<uint>& x, uint i, std::vector<uint>& r) {
        r.resize(x.size()); int ri=0, xi=i/LOGBASE; i%=LOGBASE;
        if (xi<x.size()) r[ri++] = x[xi++] >> i;
        for (; xi<x.size(); ++xi, ++ri) { if (i) r[ri-1] |= x[xi] << LOGBASE-i; r[ri] = x[xi] >> i; }
        r.resize(ri); strip(r);
    }

    inline void bit_shl(const std::vector<uint>& x, uint i, std::vector<uint>& r) {
        if (x.empty()) { r.clear(); return; }
        int xi=x.size(), ri=xi+i/LOGBASE; r.resize(ri); i%=LOGBASE;
        if (i && x[xi-1] >> LOGBASE-i) r.push_back(x[xi-1] >> LOGBASE-i);
        r[--ri] = x[--xi] << i;
        while (xi) { if (i) r[ri] |= x[xi-1] >> LOGBASE-i; r[--ri] = x[--xi] << i; }
        while (ri) r[--ri] = 0;
    }

} // namespace arith


class biguint {
    std::vector<arith::uint> buf;

public:
    biguint() {}
    explicit biguint(int x) {
        arith::assert_msg(x>=0, "Negative value");
        if (x) buf.push_back(x);
    }
    explicit biguint(unsigned int x) {
        if (x) buf.push_back(x);
    }
    explicit biguint(long long x) {
        arith::assert_msg(x>=0, "Negative value");
        if (x) buf.push_back(x);
        if (x>>arith::LOGBASE) buf.push_back(x>>arith::LOGBASE);
    }
    explicit biguint(unsigned long long x) {
        if (x) buf.push_back(x);
        if (x>>arith::LOGBASE) buf.push_back(x>>arith::LOGBASE);
    }

    biguint& operator+=(const biguint& y) {
        arith::add(buf, y.buf, buf);
        return *this;
    }
    biguint& operator-=(const biguint& y) {
        arith::assert_msg(*this>=y, "Negative value");
        arith::sub(buf, y.buf, buf);
        return *this;
    }
    biguint& operator*=(const biguint& y) {
        std::vector<arith::uint> tmp;
        arith::mul(buf, y.buf, tmp);
        buf = tmp;
        return *this;
    }
    biguint& operator*=(int a) {
        biguint *y = new biguint (a);
        std::vector<arith::uint> tmp;
        arith::mul(buf, (*y).buf, tmp);
        buf = tmp;
        return *this;
    }
    biguint& operator/=(const biguint& y) {
        arith::assert_msg(y!=biguint(0), "Div by zero");
        std::vector<arith::uint> tmp;
        arith::div(buf, y.buf, tmp);
        buf = tmp;
        return *this;
    }
    biguint& operator/=(int a) {
        biguint *y = new biguint (a);
        arith::assert_msg((*y)!=biguint(0), "Div by zero");
        std::vector<arith::uint> tmp;
        arith::div(buf, (*y).buf, tmp);
        buf = tmp;
        return *this;
    }
    biguint& operator%=(const biguint& y) {
        arith::assert_msg(y!=biguint(0), "Div by zero");
        std::vector<arith::uint> tmp;
        arith::div(buf, y.buf, tmp);
        return *this;
    }

    friend biguint operator+(const biguint& x, const biguint& y) {
        biguint z;
        arith::add(x.buf, y.buf, z.buf);
        return z;
    }
    friend biguint operator+(const biguint& x, int a) {
        biguint *y = new biguint (a),z;
        arith::add(x.buf, (*y).buf, z.buf);
        return z;
    }
    friend biguint operator-(const biguint& x, const biguint& y) {
        arith::assert_msg(x>=y, "Subtract a larger number");
        biguint z;
        arith::sub(x.buf, y.buf, z.buf);
        return z;
    }
    friend biguint operator-(const biguint& x, int a) {
        biguint *y = new biguint (a),z;
        arith::assert_msg(x>=*y, "Subtract a larger number");
        arith::sub(x.buf, (*y).buf, z.buf);
        return z;
    }
    friend biguint operator*(const biguint& x, const biguint& y) {
        biguint z;
        arith::mul(x.buf, y.buf, z.buf);
        return z;
    }
    friend biguint operator*(const biguint& x, int a) {
        biguint *y = new biguint (a),z;
        arith::mul(x.buf, (*y).buf, z.buf);
        return z;
    }
    friend biguint operator/(const biguint& x, const biguint& y) {
        arith::assert_msg(y!=biguint(0), "Div by zero");
        std::vector<arith::uint> tmp(x.buf); biguint z;
        arith::div(tmp, y.buf, z.buf);
        return z;
    }
    friend biguint operator/(const biguint& x, int a) {
        biguint *y = new biguint (a),z;
        arith::assert_msg((*y)!=biguint(0), "Div by zero");
        std::vector<arith::uint> tmp(x.buf);
        arith::div(tmp, (*y).buf, z.buf);
        return z;
    }
    friend biguint operator%(const biguint& x, const biguint& y) {
        arith::assert_msg(y!=biguint(0), "Div by zero");
        biguint z(x);
        std::vector<arith::uint> tmp;
        arith::div(z.buf, y.buf, tmp);
        return z;
    }
    friend biguint operator%(const biguint& x, int a) {
        biguint *y = new biguint (a),z(x);
        arith::assert_msg((*y)!=biguint(0), "Div by zero");
        std::vector<arith::uint> tmp;
        arith::div(z.buf, (*y).buf, tmp);
        return z;
    }

    biguint& operator&=(const biguint& y) {
        arith::bit_and(buf, y.buf, buf);
        return *this;
    }
    biguint& operator|=(const biguint& y) {
        arith::bit_or(buf, y.buf, buf);
        return *this;
    }
    biguint& operator^=(const biguint& y) {
        arith::bit_xor(buf, y.buf, buf);
        return *this;
    }
    biguint& operator>>=(int i) {
        arith::assert_msg(i>=0, "Negative value");
        arith::bit_shr(buf, i, buf);
        return *this;
    }
    biguint& operator<<=(int i) {
        arith::assert_msg(i>=0, "Negative value");
        arith::bit_shl(buf, i, buf);
        return *this;
    }
    biguint operator~() const {
        biguint z;
        arith::bit_neg(buf, z.buf);
        return z;
    }

    friend biguint operator&(const biguint& x, const biguint& y) {
        biguint z;
        arith::bit_and(x.buf, y.buf, z.buf);
        return z;
    }
    friend biguint operator|(const biguint& x, const biguint& y) {
        biguint z;
        arith::bit_or(x.buf, y.buf, z.buf);
        return z;
    }
    friend biguint operator^(const biguint& x, const biguint& y) {
        biguint z;
        arith::bit_xor(x.buf, y.buf, z.buf);
        return z;
    }
    friend biguint operator>>(const biguint& x, int i) {
        arith::assert_msg(i>=0, "Negative value");
        biguint z;
        arith::bit_shr(x.buf, i, z.buf);
        return z;
    }
    friend biguint operator<<(const biguint& x, int i) {
        arith::assert_msg(i>=0, "Negative value");
        biguint z;
        arith::bit_shl(x.buf, i, z.buf);
        return z;
    }

    bool operator!() const { return buf.empty(); }

    friend bool operator==(const biguint& x, const biguint& y) {
        return arith::cmp(x.buf.begin(), x.buf.end(), y.buf.begin(), y.buf.end()) == 0;
    }
    friend bool operator==(const biguint& x, int a) {
        const biguint *y = new biguint(a);
        return arith::cmp(x.buf.begin(), x.buf.end(), (*y).buf.begin(), (*y).buf.end()) == 0;
    }
    friend bool operator!=(const biguint& x, const biguint& y) {
        return arith::cmp(x.buf.begin(), x.buf.end(), y.buf.begin(), y.buf.end()) != 0;
    }
    friend bool operator!=(const biguint& x, int a) {
        const biguint *y = new biguint(a);
        return arith::cmp(x.buf.begin(), x.buf.end(), (*y).buf.begin(), (*y).buf.end()) != 0;
    }
    friend bool operator<(const biguint& x, const biguint& y) {
        return arith::cmp(x.buf.begin(), x.buf.end(), y.buf.begin(), y.buf.end()) < 0;
    }
    friend bool operator<(const biguint& x, int a) {
        const biguint *y = new biguint(a);
        return arith::cmp(x.buf.begin(), x.buf.end(), (*y).buf.begin(), (*y).buf.end()) < 0;
    }
    friend bool operator<=(const biguint& x, const biguint& y) {
        return arith::cmp(x.buf.begin(), x.buf.end(), y.buf.begin(), y.buf.end()) <= 0;
    }
    friend bool operator<=(const biguint& x, int a) {
        const biguint *y = new biguint(a);
        return arith::cmp(x.buf.begin(), x.buf.end(), (*y).buf.begin(), (*y).buf.end()) <= 0;
    }
    friend bool operator>(const biguint& x, const biguint& y) {
        return arith::cmp(x.buf.begin(), x.buf.end(), y.buf.begin(), y.buf.end()) > 0;
    }
    friend bool operator>(const biguint& x, int a) {
        const biguint *y = new biguint(a);
        return arith::cmp(x.buf.begin(), x.buf.end(), (*y).buf.begin(), (*y).buf.end()) > 0;
    }
    friend bool operator>=(const biguint& x, const biguint& y) {
        return arith::cmp(x.buf.begin(), x.buf.end(), y.buf.begin(), y.buf.end()) >= 0;
    }
    friend bool operator>=(const biguint& x, int a) {
        const biguint *y = new biguint(a);
        return arith::cmp(x.buf.begin(), x.buf.end(), (*y).buf.begin(), (*y).buf.end()) >= 0;
    }

    friend std::istream& operator>>(std::istream&, biguint&);
    friend std::ostream& operator<<(std::ostream&, biguint);
};

std::istream& operator>>(std::istream& is, biguint& x) {
    std::string s; is >> s;
    x.buf.clear();
    for (int i=0; i<s.size(); ++i) {
        arith::mul(x.buf, 10, x.buf);
        arith::add(x.buf, s[i]-'0', x.buf);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, biguint x) {
    std::string s;
    while (!x.buf.empty()) {
        arith::uint q = arith::div(x.buf, 10, x.buf);
        s += q+'0';
    }
    if (s.empty()) s += '0';
    std::reverse(s.begin(), s.end());
    return os << s;
}
