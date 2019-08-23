#include<bits/stdc++.h>

// WA ????

using namespace std;

const int maxn = 31;

int m, n, flood;
int region[maxn*maxn];


int main(){

    cout<<setiosflags(ios::fixed)<<setprecision(2);

    for(int turn = 1; (cin>>m>>n) && m != 0; turn++){

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>region[i*n+j];
        cin>>flood;

        sort(region, region + m*n);

        int space = 0, h = 0, flood_area = 100;
        float height;
        for(int i=1; i<m*n && space < flood; i++) {
            space += (region[i] - region[i-1]) * flood_area;
            flood_area += 100;
            h = region[i];
        }

        if(space >= flood){
            flood_area -= 100;
            height = h - (1.0 * (space - flood) / flood_area);
        }else{
            height = h + (1.0 * (flood - space) / flood_area);
        }

        cout<<"Region "<<turn<<endl;
        cout<<"Water level is "<<height<<" meters."<<endl;
        cout<<1.0*flood_area/(m*n)<<" percent of the region is under water."<<endl;
    }
}

/*
3 3
25 37 45
51 12 34
94 83 27
10000
0 0

Region 1
Water level is 46.67 meters.
66.67 percent of the region is under water.
 */