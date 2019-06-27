#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back

typedef long long ll;

using namespace std;

// https://blog.csdn.net/luoyizh1/article/details/91607244
// 矩阵快速幂、欧拉降幂

const int MAXN=5;

struct matrix{
    int i;
    ll a[MAXN][MAXN];
    ll* operator [](int x){return a[x];}
	const ll* operator [](int x)const{return a[x];}
    void diag(){
        memset(a, 0, sizeof(a));
        for(int i=0; i<MAXN; i++) a[i][i] = 1;
    }
};

matrix mmult(matrix a, matrix b, ll mod){
    matrix ans;
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++){
            ans[i][j] = 0;
            for(int k=0; k<MAXN; k++){
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= mod;
            }
        }
    return ans;
}

matrix mpow(matrix a, ll exp, ll mod){
    matrix t;
    t.diag();
    if(exp == 0) return t;
    t = mpow(a, exp>>1, mod);
    if(exp%2 == 0) return mmult(t, t, mod);
    return mmult(mmult(t, t, mod), a, mod);
}

ll qpow(ll m, ll n, ll mod){
    ll t;
    if(n == 0) return 1;
    t = qpow(m, n>>1, mod);
    if(t%2) return t*t%mod;
    return m*t*t%mod;
}

void print_mat(matrix m){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    const int mod = 1000000007;

    ll n, f1, f2, f3, c;
    cin>>n>>f1>>f2>>f3>>c;
    matrix fe, ce, fe_n, ce_n;

    // ===
    ll exp_c, cc;
    matrix a,final,temp,first;
	memset(a.a,0,sizeof(a.a));
	a.a[3][0]=2;
	a.a[4][0]=1;
	memset(first.a,0,sizeof(first.a));
	first.a[0][0]=1;
	first.a[0][1]=1;
	first.a[0][2]=1;
	first.a[0][3]=1;
	first.a[3][3]=1;
	first.a[3][4]=2;
	first.a[4][4]=1;
	first.a[1][0]=1;
	first.a[2][1]=1;
	temp=mpow(first,n-3,mod-1);
	exp_c=mmult(temp,a,mod-1).a[0][0];
	cc=qpow(c,exp_c,mod);
    cout<<exp_c<<endl;
    // ===

    memset(fe.a, 0, sizeof(fe.a));
    fe[0][0] = fe[0][1] = fe[0][2] = 1;
    fe[1][0] = fe[2][1] = 1;
    
    // print_mat(mpow(fe, 0, mod-1));
    // print_mat(mmult(fe, fe, mod));

    fe_n = mpow(fe, n-3, mod - 1); // 都是在指数上运行的，所以取模为mod-1
    ll fn = qpow(f3, fe_n[0][0], mod);
    cout<<fn<<endl;
    fn = (fn * qpow(f2, fe_n[0][1], mod)) % mod;
    fn = (fn * qpow(f1, fe_n[0][2], mod)) % mod;

    print_mat(fe_n);
    cout<<fn<<endl;

    // memset(ce.a, 0, sizeof(ce.a));
    // ce[0][0] = ce[0][1] = ce[0][2] = ce[0][3] = 1;
    // ce[1][0] = 1;
    // ce[2][1] = 1;
    // ce[3][3] = 1; ce[3][4] = 2;
    // ce[4][4] = 1;
    // ce_n = mpow(ce, n-3, mod - 1);
    // ll cn = qpow(ce_n[0][3], 2*n-6, mod);
    // cout<<fn<<" "<<cn<<endl;
    
    // cout<<(fn*cn)%mod<<endl; // 实际上这两个矩阵计算一个就行
}
