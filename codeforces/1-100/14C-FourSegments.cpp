#include <iostream>
#include <set>
using namespace std;


int x0[4], y0[4], x1[4], y1[4], t;

int main() {
    for (int i = 0; i < 4; ++i) {
        cin>>x0[i]>>y0[i]>>x1[i]>>y1[i];
        if(x0[i]>x1[i]){
            t = x0[i];
            x0[i] = x1[i];
            x1[i] = t;
        }
        if(y0[i]>y1[i]){
            t = y0[i];
            y0[i] = y1[i];
            y1[i] = t;
        }
    }
    bool ok=true;
    int cnt = 0;
    for(int i=0;i<4;i++){
        cnt=0;
        for(int j=0; j<4; j++){
            if(i==j)continue;
            if(x0[j]==x0[i]&&y0[j]!=y0[i]&&x1[j]==x1[i]&&y1[j]-y0[j]==y1[i]-y1[i])
                cnt+=1;
            if(x0[j]!=x0[i]&&y0[j]==y0[i]&&y1[j]==y1[i]&&x1[j]-x0[j]==x1[i]-x1[i])
                cnt+=1;
        }

        bool find0 = false, find1 = false;
        for(int j=0;j<4;j++) {
            if (j == i)continue;
            if (x0[i] == x0[j] && y0[i] == y0[j] || x0[i] == x1[j] && y0[i] == y1[j]) {
                find0 = true;
                break;
            }
        }
        for(int j=0;j<4;j++){
            if(j==i)continue;
            if(x1[i]==x0[j]&&y1[i]==y0[j] || x1[i]==x1[j]&&y1[i]==y1[j]){
                find1 = true;
                break;
            }
        }

        if(cnt!=1 || (x0[i]==x1[i]&&y0[i]==y1[i]) || !find0 || !find1){
            ok=false;
            break;
        }
    }

    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
