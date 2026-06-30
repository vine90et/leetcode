class Solution {
public:
    int n, m;
    vector<int> dirR{1, -1, 0, 0};
    vector<int> dirC{0, 0, 1, -1};
    void dfs(vector<vector<char>>& grid, int row, int col){

        grid[row][col] = '0'; 

        for(int i = 0;i < 4;i++){
            int nextR = row + dirR[i];
            int nextC = col + dirC[i];

            if(nextR < n && nextR >= 0 && nextC >= 0 &&  nextC < m && grid[nextR][nextC] == '1'){    
                dfs(grid, nextR, nextC);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};