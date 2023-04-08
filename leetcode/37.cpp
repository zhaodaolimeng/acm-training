#include<bits/stdc++.h>

using namespace std;

class Solution {

    vector<pair<int,int> >* guess;
    vector<vector<int> >* colcnt;
    vector<vector<int> >* rowcnt;
    vector<vector<vector<int>> >* ninecnt;

    bool dfs(int n, vector<vector<char>>& board){
        if(n == guess->size()) return true;
        int x = guess->at(n).first;
        int y = guess->at(n).second;

        // guess current position

        for(int i=0;i<9;i++){
            if(colcnt->at(x)[i]==0 && rowcnt->at(y)[i]==0 && ninecnt->at(x/3)[y/3][i]==0){
                board[x][y] = (char)('1'+i);
                colcnt->at(x)[i]++;
                rowcnt->at(y)[i]++;
                ninecnt->at(x/3)[y/3][i]++;
                bool ret = dfs(n+1,board);
                if(ret) return true;
                colcnt->at(x)[i]--;
                rowcnt->at(y)[i]--;
                ninecnt->at(x/3)[y/3][i]--;
                board[x][y] = '.';
            }
        }
        return false;
    }
    
public:

    void solveSudoku(vector<vector<char>>& board) {
        guess = new vector<pair<int,int>>();
        colcnt = new vector<vector<int>>(9,vector<int>(9,0));
        rowcnt = new vector<vector<int>>(9,vector<int>(9,0));
        ninecnt = new vector<vector<vector<int>>>(3,vector<vector<int>>(3,vector<int>(9,0)));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    guess->push_back(make_pair(i,j));
                }else{
                    colcnt->at(i)[board[i][j] - '1'] += 1;
                    rowcnt->at(j)[board[i][j] - '1'] += 1;
                    ninecnt->at(i/3)[j/3][board[i][j] - '1'] += 1;
                }
            }
        }
        dfs(0,board);
    }
};

int main(){
    Solution sl;
    vector<vector<char>> sd {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    sl.solveSudoku(sd);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sd[i][j];
        }
        cout<<endl;
    }
    return 0;
}
