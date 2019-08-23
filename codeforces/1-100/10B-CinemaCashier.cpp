/**
 * codeforces 10B
 * ==============
 * 为电影院自动选号，K行作为，每行K的用户，用户是以团队用户的形式参与，要求N组用户各组都在一排。
 * 目标是给出作为方案使得所有用户距离放映厅中心距离最小。
 * 但这道题目不是为了获得全局最优，而是顺序地对各组进行排序。
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

int mp[1002][1002];

int main() {

    int N, K, M, ans = 0;
    cin>>N>>K;
    int xc = (1 + K)/2, yc = (1 + K)/2;

    for(int i=0; i<N; i++){
        cin>>M;
        int v = 0, minv = (1<<30);
        int xt = 0, yt = 0;

        for(int x=1; x<=K; x++){
            for(int y=1; y<=K-M+1; y++){
                bool ok = true;
                v = M * abs(x - xc);
                for(int m=0; m<M; m++){
                    if(mp[x][y+m]==1){
                        ok = false;
                        break;
                    }else{
                        v += abs(y + m - yc);
                    }
                }
                if(ok && v<minv){
                    minv = v;
                    xt = x, yt = y;
                }
//                cout<<v<<"\t";
            }
//            cout<<endl;
        }
//        cout<<"======"<<endl;

        for(int m=0; m<M; m++) mp[xt][yt + m] = 1;
        if(xt == 0)
            cout<<-1<<endl;
        else
            cout<<xt<<" "<<yt<<" "<<yt+M-1<<endl;

//        cout<<endl;
//        for(int x=1; x<=K; x++) {
//            for (int y = 1; y <= K; y++)
//                cout<<mp[x][y]<<" ";
//            cout<<endl;
//        }
    }
    return 0;
}
