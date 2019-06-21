#include<iostream>
#include<map>

using namespace std;

int b[200010];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++) scanf("%d", &b[i]);

    if(n <= 3) {
        cout<<0<<endl;
        return 0;
    }

    sort(b, b+n);
    map<int, int> m;

    for(int i=1; i<n; i++){
        if(m.count(b[i] - b[i-1]) == 0)
            m[b[i] - b[i-1]] = 0;
        m[b[i] - b[i-1]]++;
    }

    int target = -1;
    for(auto const & p : m){
        if(p.second > 1){
            target = p.first;
            break;
        }
    }

    int index = -1;
    for(int i=0; i<n; i++){
        if(b[i] == target){
            index = i;
            break;
        }
    }

    cout<<index + 1<<endl;
    return 0;
}
