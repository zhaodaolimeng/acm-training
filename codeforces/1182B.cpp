#include <iostream>

using namespace std;

bool vis[510][510];
char pic[510][510];
int h, w, x, y;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool solve(){
    bool ok;
    int cnt = 0;

    for(int i=1; i<h-1; i++)
        for(int j=1; j<w-1; j++){
            if(pic[i][j] == '.' || vis[i][j]) continue;
            ok = true;
            for(int k=0; k<4; k++){
                x = i, y = j;
                while(x+dx[k]>=0 && x+dx[k]<h && y+dy[k]>=0 && y+dy[k]<w &&
                    pic[x+dx[k]][y+dy[k]] == '*'){
                    vis[x+dx[k]][y+dy[k]] = true;
                    x += dx[k];
                    y += dy[k];
                }
                if(x == i && y == j){
                    ok = false;
                    break;
                }
            }
            if(ok){
                vis[i][j] = true;
                cnt ++;
            }
        }
    
    // cout<<"======"<<endl;
    // for(int i=0; i<h; i++){
    //     for(int j=0; j<w; j++){
    //         cout<<vis[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<cnt<<endl;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(pic[i][j] == '*' && vis[i][j] == false)
                return false;
        }
    }
    if(cnt != 1) return false;
    return true;
}

int main(){
    cin>>h>>w;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>pic[i][j];
    
    if(solve()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
