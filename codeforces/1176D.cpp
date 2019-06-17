#include <set>
#include <iostream>

using namespace std;

// http://codeforces.com/contest/1176/submission/55378198

const int MAX_P = 3000000;
int primes[MAX_P];  // 0意味着是素数，否则存储最大因子
int index[MAX_P];
int n, b, t;

int main(){
    int prime_index = 0;
    for(int i=2; i < MAX_P && i*1LL*i < MAX_P; i++){
        if(primes[i]) continue;
        index[i] = ++prime_index;
        for(int j=i*i; j < MAX_P; j+=i)
            if(!primes[j]) primes[j]=i;
    }
    cin>>n;

    multiset<int> s;
    for(int i=1; i<=2*n; i++){
        cin>>b;
        s.insert(b);
    }

    while(!s.empty()){
        t = *s.rbegin();  // 从后向前
        s.erase(s.find(t));
        if(!primes[t]){  // 是素数，返回素数的编号
            cout<<index[t]<<" ";
            s.erase(s.find(index[t]));
        }else{
            cout<<t<<" ";
            s.erase(s.find(t/primes[t]));  // 清除b中由a中非素数引入的结果
        }
    }
    cout<<endl;
    return 0;
}
