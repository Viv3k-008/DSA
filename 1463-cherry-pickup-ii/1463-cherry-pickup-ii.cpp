class Solution {
public:
    vector<vector<vector<int>>> dp;
    int fn(int i, int j1, int j2, vector<vector<int>>& grid){
        if(i == grid.size()){
            return 0;
        }
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()){
            return -1e9;
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int cost = (j1 == j2)? grid[i][j1] : grid[i][j1] + grid[i][j2];

        int cur = INT_MIN;

        int d[3] = {-1, 0, 1};
        for(int l = 0 ; l < 3 ; l++){
            for(int m = 0 ; m < 3 ; m++){
                cur = max(cur, cost + fn(i+1, j1+d[l], j2+d[m], grid));
            }
        }
        
        return dp[i][j1][j2] = cur;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return fn(0, 0, grid[0].size()-1, grid);
    }
};