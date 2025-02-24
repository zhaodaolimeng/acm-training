#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    vector<pair<int,int>> dir={
        make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)
    };
    int rn=matrix.size();
    int cn=matrix[0].size();
    int t,perimeter,x,y,cur_dir,xx,yy;
    
    for(int c=0;c<min(rn,cn)/2;c++){
        perimeter=(rn+cn)*2-4-8*c;
        for(int i=0;i<r%perimeter;i++){
            x=c,y=c;
            t=matrix[x][y];
            cur_dir=0;
            for(int j=0;j<perimeter-1;j++){
                xx=x+dir[cur_dir].first;
                yy=y+dir[cur_dir].second;
                if(cur_dir==0 && yy>=cn-c || cur_dir==1 && xx>=rn-c || cur_dir==2 && yy<c) cur_dir++;
                xx=x+dir[cur_dir].first;
                yy=y+dir[cur_dir].second;
                matrix[x][y]=matrix[xx][yy];
                x=xx,y=yy;
            }
            matrix[x][y]=t;
        }
    }
    
    for(int i=0;i<rn;i++){
        for(int j=0;j<cn;j++){
            if(j==0) cout<<matrix[i][j];
            else cout<<" "<<matrix[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    ifstream cin("input.txt");
    int m,n,r,t;
    cin>>m>>n>>r;

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin>>t;
            matrix[i][j] = t;
        }
    }

    matrixRotation(matrix, r);
    return 0;
}
