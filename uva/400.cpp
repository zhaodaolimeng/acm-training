#include <bits/stdc++.h>

using namespace std;

const int maxn = 60;

void print_space(int n){
    for(int i=0; i<n; i++) cout<<" ";
}

int main(){

    int cnt;
    string s;

    while(cin>>cnt){

        int max_len = 0;
        vector<string> vs;

        for(int i=0; i<cnt; i++) {
            cin>>s;
            vs.push_back(s);
            if(s.size() > max_len) max_len = s.size();
        }

        sort(vs.begin(), vs.end());

        int col = maxn / (max_len + 2);
        if(col * (max_len + 2) + max_len <= maxn) col += 1;
        
        for(int i=0; i<maxn; i++) cout<<"-";
        cout<<endl;

        int row = vs.size() / col;
        int n_last_col = vs.size() % col;
        if(n_last_col != 0) row += 1;
        
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                s = "";
                if(c*row + r < vs.size()) s = vs[c*row + r];
                cout<<s;
                if(c != col - 1){
                    print_space(max_len + 2 - s.size());
                }else{
                    print_space(max_len - s.size());
                }
            }
            cout<<endl;
        }
    }
}

/*
10
tiny
2short4me
very_long_file_name
shorter
size-1
size2
size3
much_longer_name
12345678.123
mid_size_name
12
Weaser
Alfalfa
Stimey
Buckwheat
Porky
Joe
Darla
Cotton
Butch
Froggy
Mrs_Crabapple
P.D.
19
Mr._French
Jody
Buffy
Sissy
Keith
Danny
Lori
Chris
Shirley
Marsha
Jan
Cindy
Carol
Mike
Greg
Peter
Bobby
Alice
Ruben

 */