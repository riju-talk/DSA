#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        set<pair<int,int>> visited;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int length = 0;
                if(dfs(board, word, visited, length, j, i)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string word, set<pair<int,int>>& visited, int length, int col, int row){
        if(length==word.length()) return true;
        if(col < 0 || col >= board[0].size()) return false;
        if(row < 0 || row >= board.size()) return false;
        if(visited.count({row, col})) return false;
        if(board[row][col] != word[length]) return false;


        visited.insert({row, col});

        bool found = dfs(board, word, visited, length+1, col+1, row) || 
        dfs(board, word, visited, length+1, col, row+1) || 
        dfs(board, word, visited, length+1, col, row-1) || 
        dfs(board, word, visited, length+1, col-1, row);
        visited.erase({row,col});
        return found;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "SFBA";

    if(sol.exist(board, word)) cout << "Found\n";
    else cout << "Not Found\n";

    return 0;
}
