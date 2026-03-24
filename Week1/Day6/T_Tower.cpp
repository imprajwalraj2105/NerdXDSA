#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> result;

bool isSafe(vector<string>& board, int row, int col){
    // check column
    for(int i = 0; i < row; i++){
        if(board[i][col] == 'T') return false;
    }

    // left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'T') return false;
    }

    // right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 'T') return false;
    }

    return true;
}

void solve(int row, vector<string>& board){
    if(row == n){
        result.push_back(board);
        return;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(board, row, col)){
            board[row][col] = 'T';
            solve(row + 1, board);
            board[row][col] = '.'; // backtrack
        }
    }
}

int main(){
    cin >> n;

    vector<string> board(n, string(n, '.'));

    solve(0, board);

    if(result.empty()){
        cout << "No valid configurations";
        return 0;
    }

    for(int k = 0; k < result.size(); k++){
        for(string row : result[k]){
            cout << row << "\n";
        }
        if(k != result.size() - 1) cout << "\n";
    }

    return 0;
}