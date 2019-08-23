#include<bits/stdc++.h>

using namespace std;

int rotate_map[3][6] = {
    {2, 6, 3, 4, 1, 5},
    {1, 3, 5, 2, 4, 6},
    {3, 2, 6, 1, 5, 4}
};

char A[6], B[6];

void rotate(char *a, int p){
    char t[6];
    for(int i=0; i<6; i++) t[i] = a[i];
    for(int i=0; i<6; i++) a[i] = t[rotate_map[p][i] - 1];
}

bool same(char *a, char *b){
    for(int i=0; i<6; i++)
        if(a[i] != b[i]) return false;
    return true;
}

int main(){
    while(cin>>A[0]){
        for(int i=1; i<6; i++) cin>>A[i];
        for(int i=0; i<6; i++) cin>>B[i];

        bool found = false;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                for(int k=0; k<4; k++){
                    if(same(A, B)) found = true;
                    rotate(B, 2);
                }
                rotate(B, 1);
            }
            rotate(B, 0);
        }

        if(found) cout<<"TRUE"<<endl;
        else cout<<"FALSE"<<endl;
    }
    return 0;
}
