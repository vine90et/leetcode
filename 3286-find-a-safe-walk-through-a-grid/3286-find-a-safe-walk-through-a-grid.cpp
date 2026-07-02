class Solution {
public:
    int m,n;
    bool dfs(vector<vector<int>>& grid, int health, int i, int j, vector<vector<int>> &best){
        if(i >= m || i < 0 || j >= n || j < 0) return false;

        if(health <= 0) return false;

        if(i == m-1 && j == n-1) return true;

        if (health <= best[i][j])
            return false;

        best[i][j] = health;

        vector<int> dirX{1,-1,0,0}; 
        vector<int> dirY{0,0,1,-1}; 

        for(int dir = 0; dir < 4; dir++){
            int x = i + dirX[dir];
            int y = j + dirY[dir];
            if(x >= 0 && x < m && y >= 0 && y < n){
                int newHealth = health - grid[x][y];
                if(dfs(grid, newHealth, x, y, best)) return true;
            }
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();    
        n = grid[0].size();

        health -= grid[0][0];
        if (health <= 0)
            return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        return dfs(grid, health, 0, 0, best);
    }
};