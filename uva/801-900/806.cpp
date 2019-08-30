#include <bits/stdc++.h>

using namespace std;

vector<int> ans_seq;

void dfs(vector<vector<char>> image, int x, int y, int w, string pre, int idx){
    bool same = true;
    for(int i=0; i<w; i++){
        for(int j=0; j<w; j++)
            if(image[x+i][y+j] != image[x][y]){
                same = false;
                break;
            }
        if(!same) break;
    }
    string base5 = to_string(idx) + pre;
    if(same){
        if(image[x][y] == '1') {
            int result = 0;
            for(int i=0; i<base5.size(); i++){
                result *= 5;
                result += base5[i]-'0';
            }
            ans_seq.push_back(result);
        }
    }else{
        dfs(image, x, y, w/2, base5, 1);
        dfs(image, x+w/2, y, w/2, base5, 2);
        dfs(image, x, y+w/2, w/2, base5, 3);
        dfs(image, x+w/2, y+w/2, w/2, base5, 4);
    }
}

void image_to_sequence(vector<vector<char>> image){
    ans_seq.clear();
    dfs(image, 0, 0, image.size(), "", 1);
    sort(ans_seq.begin(), ans_seq.end());

    if(ans_seq.size()>0){
        cout<<ans_seq[0];
        for(int i=1; i<ans_seq.size(); i++) cout<<" "<<ans_seq[i];
        cout<<endl;
    }
    printf("Total number of black nodes = %d\n\n", (int)ans_seq.size());
}

void sequence_to_image(int w, vector<int> seq){
    vector<vector<char>> image(w, vector<char>(w, '.'));

    for(int i=0; i<seq.size(); i++){
        int t = seq[i];
        string base5;
        while(t>0){
            base5 += to_string(t%5);
            t /= 5;
        }
        int x=0, y=0, wt=w;
        for(int j=base5.size()-1; j>=0; j--){
            if(base5[j] == 2) x += wt/2;
            else if(base5[j] == 3) y += wt/2;
            else if(base5[j] == 4) {
                x += wt/2;
                y += wt/2;
            }
            wt /= 2;
        }
        for(int xt=x; xt<wt; xt++){
            for(int yt=y; yt<wt; yt++){
                image[xt][yt] = '*';
            }
        }
    }
    for(int i=0; i<w; i++){
        for(int j=0; j<w; j++) cout<<image[i][j];
        cout<<endl;
    }
    cout<<endl;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, t, kase = 1;
    char c;
    while(cin>>n && n!=0){
        cout<<"Image "<<kase<<endl;
        if(n > 0){
            vector<vector<char>> image;
            for(int i=0; i<n; i++){
                vector<char> vc;
                for(int j=0; j<n; j++) {
                    cin>>c;
                    vc.push_back(c);
                }
                image.push_back(vc);
            }
            image_to_sequence(image);
        }else{
            vector<int> seq;
            while(cin>>t && t!=-1) seq.push_back(t);
            sequence_to_image(-n, seq);
        }
        kase ++;
    }
}
