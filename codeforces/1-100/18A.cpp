#include <iostream>

using namespace std;

int dist(int x0, int y0, int x1, int y1){
    return (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1);
}

bool is_right(int x[], int y[]){
    int d01, d02, d12;
    d01 = dist(x[0], y[0], x[1], y[1]);
    d02 = dist(x[0], y[0], x[2], y[2]);
    d12 = dist(x[1], y[1], x[2], y[2]);
    if(d01 + d02 == d12 || d01 == d02 + d12 || d02 == d01 + d12)
        if((y[2]-y[1])*(x[2]-x[0]) != (x[2]-x[1])*(y[2]-y[0]))
            return true;
    return false;
}

bool is_almost(int x[], int y[]){
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            x[j] += dx[i];
            y[j] += dy[i];
            if(is_right(x, y)){
                return true;
            }
            x[j] -= dx[i];
            y[j] -= dy[i];
        }
    }
    return false;
}

int main(){
    int x[3], y[3];
    
    for(int i=0; i<3; i++) cin>>x[i]>>y[i];

    if(is_right(x, y)){
        cout<<"RIGHT"<<endl;
    }else if(is_almost(x, y)){
        cout<<"ALMOST"<<endl;
    }else cout<<"NEITHER"<<endl;
    return 0;
}


// 0 0 1 0 4 1
