#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    string s;
    vector<string> B;
    int ret = 0;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>s;
        B.push_back(s);
    }

    for(int xi=0; xi<n-2; xi++){
        for(int xd=1; xi+3*xd<n; xd++){ // FIXME xi+3*xd<=n
            int ymax = 0;
            int x1 = xi;
            int x2 = xi + xd;
            int x3 = xi + 2*xd;

            cout<<"==="<<endl;
            printf("%d %d %d\n", x1, x2, x3);

            for(int y=0; y<m; y++){
                if(B[x1][y]==B[x2][y] ||
                   B[x2][y]==B[x3][y] ||
                   B[x3][y]==B[x1][y]) continue;
                cout<<"+++"<<endl;
                bool ok = true;
                for(int d=1; d<=xd; d++){
                    if(B[x1+d][y]!=B[x1+d-1][y] || 
                       B[x2+d][y]!=B[x2+d-1][y] ||
                       B[x3+d][y]!=B[x3+d-1][y]){
                        ok = false; break;
                    }
                }
                cout<<ok<<endl;
                if(ok){
                    for(int dy=y+1; dy<m; dy++){
                        bool equals = true;
                        for(int x0=xi; x0<xi+3*xd; x0++)
                            if(B[dy] != B[dy-1]){
                                equals = false;
                                break;
                            }
                        if(!equals){
                            ymax = dy;
                            ret += (ymax-y) * (ymax-y-1)/2;
                            break;
                        }
                    }
                    y = ymax + 1;
                }
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}
