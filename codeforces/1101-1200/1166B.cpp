#include <bits/stdc++.h>

using namespace std;

char m[5][5];
char vow[5] = {'a', 'e', 'i', 'o', 'u'};

// practice
bool search(int x, int y){
    bool ok = false;
    for(int k=0; k<5; k++){
        int c = vow[k];

        bool bad = false;
        for(int i=0; i<x; i++){
            if(m[i][y] == c){
                bad = true;
                break;
            }
        }
        for(int i=0; i<y; i++){
            if(m[x][i] == c){
                bad = true;
                break;
            }
        }
        if(!bad) {
            m[x][y] = c;
            if(x == 4 && y == 4){
                return true;
            }else if(y == 4){
                ok = search(x + 1, 0) || ok;
            }else{
                ok = search(x, y + 1) || ok;
            }
            if(ok) break;
        }
    }
    return ok;
}

int main(){

    int k, f = -1;
    cin>>k;
    for(int i=5; i*i<=k; i++){
        if(k % i == 0){
            f = i;
            break;
        }
    }
    search(0, 0);
    if(f == -1){
        cout<<-1<<endl;
    }else{
        int b = k / f;
        for(int i=0; i<b; i++){
            for(int j=0; j<f; j++){
                if(i < 5 && j < 5) cout<<m[i][j];
                else if(i >= 5 && j < 5) cout<<vow[j];
                else if(i < 5 && j >= 5) cout<<vow[i];
                else cout<<'a';
            }
        }
    }
    return 0;
}
