#include<bits/stdc++.h>

using namespace std;

int n_disk, block_size, block_per_disk;  // disk数目、每个block的大小、每个disk上的block的个数
char ps;  // parity signal，奇校验还是偶校验
char raid[7][7000];

string hex_map = "0123456789ABCDEF";

string fix(){

    string binary, ans;
    
    for(int i=0; i<block_per_disk; i++){
        for(int j=0; j<block_size; j++){
            int cntx = 0, cnt1 = 0, xpos;
            for(int k=0; k<n_disk; k++){
                char c = raid[k][i*block_size + j];
                if(c == 'x') {
                    cntx ++;
                    xpos = k;
                }else if(c == '1') cnt1 ++;
            }

            if(cntx > 1) return "";
            else if(cntx == 1){
                if(ps == 'E' && cnt1%2 == 0 || ps == 'O' && cnt1%2 == 1)
                    raid[xpos][i*block_size + j] = '0';
                else
                    raid[xpos][i*block_size + j] = '1';
            }else{
                if(ps == 'E' && cnt1%2 == 1 || ps == 'O' && cnt1%2 == 0)
                    return "";
            }
        }
        for(int k=0; k<n_disk; k++){
            if(k == i%n_disk) continue;
            for(int j=0; j<block_size; j++)
                binary += raid[k][i*block_size + j];
        }
    }

    int hex = 0, extra_zero = 4 - binary.size()%4;
    if(extra_zero == 4) extra_zero = 0;
    for(int i=0; i<extra_zero; i++) binary += '0';

    // cout<<binary<<endl;
    for(int i=0; i<binary.size(); i++){
        hex = (hex<<1) + (binary[i] - '0');
        if(i % 4 == 3){
            ans += hex_map[hex];
            hex = 0;
        }
    }
    return ans;
}


int main(){
    for(int ds = 1; cin>>n_disk && n_disk != 0; ds++){
        cin>>block_size>>block_per_disk>>ps;
        for(int i=0; i<n_disk; i++) cin>>raid[i];
        string result = fix();

        if(result.size() == 0)
            cout<<"Disk set "<<ds<<" is invalid."<<endl;
        else
            cout<<"Disk set "<<ds<<" is valid, contents are: "<<result<<endl;
    }
}

/*

5 2 5
E
0001011111
0110111011
1011011111
1110101100
0010010111
3 2 5
E
0001111111
0111111011
xx11011111
3 5 1
O
11111
11xxx
x1111
2 2 3
E
101100
101100
0

Disk set 1 is valid, contents are: 6C7A79EDFC
Disk set 2 is invalid.
Disk set 3 is valid, contents are: FFC

 */