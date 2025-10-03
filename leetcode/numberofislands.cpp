#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        set<pair<int,int>> visited;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0' || visited.count({i,j})) continue;
                bool flag = bfs(grid, i, j, visited); 
                if(flag) ans++;
            }
        }
        return ans;
    }
private:
    bool bfs(vector<vector<char>>& grid, int row, int col, set<pair<int, int>>& visited){
        if(visited.count({row, col})) return false;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row,col});
        visited.insert({row,col});
        vector<int> row_ops = {1,-1,0,0};
        vector<int> col_ops = {0,0,1,-1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                if(node.first+row_ops[i]>=0 && node.first+row_ops[i]<n && node.second+col_ops[i]<m && node.second+col_ops[i]>=0 
                    && grid[node.first+row_ops[i]][node.second+col_ops[i]]=='1' && !visited.count({node.first+row_ops[i], node.second+col_ops[i]}) ){
                    visited.insert({node.first+row_ops[i], node.second+col_ops[i]});
                    q.push({node.first+row_ops[i], node.second+col_ops[i]});
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
    };

    int ans = sol.numIslands(grid);
    cout << ans << "\n";
    return 0;
}
