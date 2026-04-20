class Solution {
public:
    int fn(int i , int j , vector<vector<int>>& grid , int n , int m , vector<vector<int>>& dp){
        if(i == n-1 && j == m-1){
            if(grid[i][j] > 0) return 1;
            else return abs(grid[i][j])+1;
        }
        else if(i >= n || j >= m) return 1e9;

        if(dp[i][j] != 1e9) return dp[i][j];

        int op1 = fn(i+1 , j , grid , n , m , dp);
        int op2 = fn(i , j+1 , grid , n , m , dp);

        int req = min(op1 , op2);
        if(grid[i][j] >= req){
            return dp[i][j] = 1;
        }
        else return dp[i][j] = abs(grid[i][j] - req);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size() , m = dungeon[0].size();

        vector<vector<int>> dp(n , vector<int>(m , 1e9));
        return fn(0 , 0 , dungeon , n , m , dp);
    }
};