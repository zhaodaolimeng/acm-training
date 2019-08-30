#include <bits/stdc++.h>

using namespace std;

vector<int> ans_seq;

void dfs(vector<vector<char>> image, int x, int y, int w, string pre){
    bool same = true;
    for(int i=0; i<w; i++){
        for(int j=0; j<w; j++)
            if(image[x+i][y+j] != image[x][y]){
                same = false;
                break;
            }
        if(!same) break;
    }
    string base5 = pre;
    if(same){
        if(image[x][y] == '1') {
            int result = 0;
            for(int i=0; i<base5.size(); i++){
                result *= 5;
                result += base5[i]-'0';
            }
            // cout<<x<<" "<<y<<" "<<base5<<" "<<result<<endl;
            ans_seq.push_back(result);
        }
    }else{
        dfs(image, x, y, w/2, to_string(1) + base5);
        dfs(image, x, y+w/2, w/2, to_string(2) + base5);
        dfs(image, x+w/2, y, w/2, to_string(3) + base5);
        dfs(image, x+w/2, y+w/2, w/2, to_string(4) + base5);
    }
}

void image_to_sequence(vector<vector<char>> image){
    ans_seq.clear();
    dfs(image, 0, 0, image.size(), "");
    sort(ans_seq.begin(), ans_seq.end());

    if(ans_seq.size()>0){
        int mod12 = ans_seq.size() % 12, div12 = ans_seq.size()/12, t;
        for(int i=0; i<div12; i++){
            t = i*12;
            cout<<ans_seq[t];
            for(int j=1; j<12; j++) cout<<" "<<ans_seq[t + j];
            cout<<endl;
        }
        if(mod12 != 0){
            cout<<ans_seq[div12*12];
            for(int j=1; j<mod12; j++) cout<<" "<<ans_seq[div12*12 + j];
            cout<<endl;
        }
    }
    cout<<"Total number of black nodes = "<<ans_seq.size()<<endl;
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
        for(int j=0; j<base5.size(); j++){
            if(base5[j] == '3') x += wt/2;
            else if(base5[j] == '2') y += wt/2;
            else if(base5[j] == '4') {
                x += wt/2;
                y += wt/2;
            }
            wt /= 2;
        }
        // printf("%d %s %d %d %d\n", seq[i], base5.c_str(), x, y, wt);
        for(int xt=0; xt<wt; xt++){
            for(int yt=0; yt<wt; yt++){
                image[x+xt][y+yt] = '*';
            }
        }
    }
    for(int i=0; i<w; i++){
        for(int j=0; j<w; j++) cout<<image[i][j];
        cout<<endl;
    }
}


int main(){
    std::ios::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, t, kase = 1;
    bool first = true;
    char c;
    while(cin>>n && n!=0){
        if(first) first = false;
        else cout<<endl;
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
