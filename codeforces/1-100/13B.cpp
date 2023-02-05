#include <bits/stdc++.h>

using namespace std;

struct Segment{
    int x0,y0,x1,y1;
}seg[3];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<3;i++){
            cin>>seg[i].x0>>seg[i].y0>>seg[i].x1>>seg[i].y1;
        }
        int cnt_same_pts = 0;
        int a,b,c;
        for(int i=0;i<3;i++){
            for(int j=0;j<i;j++){
                if((seg[i].x0 == seg[j].x0 && seg[i].y0 == seg[j].y0)||
                    (seg[i].x0 == seg[j].x1 && seg[i].y0 == seg[j].y1)){
                    cnt_same_pts ++;
                    a = i;
                    b = j;
                }
                if((seg[i].x1 == seg[j].x0 && seg[i].y1 == seg[j].y0)||
                    (seg[i].x1 == seg[j].x1 && seg[i].y1 == seg[j].y1)){
                    cnt_same_pts ++;
                    a = i;
                    b = j;
                }
            }
        }
        if(cnt_same_pts != 1) {
            cout<<"NO"<<endl;
            continue;
        }

        // angle between a and b is less than 90 degree
        double ab = (seg[a].x0-seg[a].x1)*(seg[b].x0-seg[b].x1) + (seg[a].y0-seg[a].y1)*(seg[b].y0-seg[b].y1);
        
        if((seg[a].x0 == seg[b].x0 && seg[a].y0 == seg[b].y0)||
            (seg[a].x1 == seg[b].x1 && seg[a].y1 == seg[b].y1) && ab < 0){
            cout<<"NO"<<endl;
            continue;
        }
        if((seg[a].x0 == seg[b].x1 && seg[a].y0 == seg[b].y1)||
            (seg[a].x1 == seg[b].x0 && seg[a].y1 == seg[b].y0) && ab > 0){
            cout<<"NO"<<endl;
            continue;
        }

        // split between 1/4 and 3/4
        for(int i=0;i<3;i++){
            if(i!=a && i!=b) {
                c = i;
                break;
            }
        }

        double ka = (seg[a].x1-seg[a].x0)/(seg[a].y1-seg[a].y0);
        double kb = (seg[c].x1-seg[c].x0)/(seg[c].y1-seg[c].y0);
        double y = ((seg[c].x0-seg[a].x0)+(ka*seg[a].y0-kb*seg[c].y0))/(ka-kb);
        if(min(abs(seg[a].y0-y),abs(seg[a].y1-y))*4<abs(seg[a].y0-seg[a].y1)){
            cout<<"NO"<<endl;
            continue;
        }

        ka = (seg[b].x1-seg[b].x0)/(seg[b].y1-seg[b].y0);
        kb = (seg[c].x1-seg[c].x0)/(seg[c].y1-seg[c].y0);
        y = ((seg[c].x0-seg[b].x0)+(ka*seg[b].y0-kb*seg[c].y0))/(ka-kb);
        if(min(abs(seg[b].y0-y),abs(seg[b].y1-y))*4<abs(seg[b].y0-seg[b].y1)){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
    }
    return 0;
}


/*
3
4 4 6 0
4 1 5 2
4 0 4 4
0 0 0 6
0 6 2 -4
1 1 0 1
0 0 0 5
0 5 2 -1
1 2 0 1

*/