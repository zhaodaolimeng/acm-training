#include <bits/stdc++.h>

using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int vis[8][8];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s0, s1;
    int x0,y0, x1,y1, xt, yt;
    while(cin>>s0){
        cin>>s1;

        x0 = s0[0]-'a';
        y0 = s0[1]-'1';
        x1 = s1[0]-'a';
        y1 = s1[1]-'1';

        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++) vis[i][j] = 0;

        queue<pair<int,int>> q;
        pair<int,int> p, pt;
        
        q.push(make_pair(x0, y0));
        vis[x0][y0] = 1;

        int step = 0;
        bool found = false;

        if(x0 == x1 && y0 == y1){
            found = true;
            step = -1;
            q.pop();
        }
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                p = q.front(); q.pop();
                for(int k=0;k<8; k++){
                    xt = p.first + dx[k], yt = p.second + dy[k];
                    if(xt>=0 && xt<8 && yt>=0 && yt<8 && vis[xt][yt]==0){
                        vis[xt][yt] = 1;
                        if(xt==x1 && yt==y1){
                            found = true;
                            break;
                        }
                        q.push(make_pair(xt, yt));
                    }
                }
                if(found) break;
            }
            if(found) break;
            step++;
        }
        if(found)
            printf("To get from %s to %s takes %d knight moves.\n", s0.c_str(), s1.c_str(), step+1);
    }


}