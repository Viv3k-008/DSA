class Solution {
public:
   
    int fn(vector<vector<int>>& grid , vector<vector<vector<vector<int>>>>& dp , int n , int i1 , int j1 , int i2 , int j2){
        if(i1 == n-1 && j1 == n-1 && i2 == n-1 && j2 == n-1){
            return grid[i1][j1];
        }
        
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return INT_MIN;

        

        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];

        int cheries = 0;
        if(i1 == i2 && j1 == j2){
            cheries = grid[i1][j1];
        }
        else cheries = grid[i1][j1] + grid[i2][j2];

        int DD = fn(grid , dp , n , i1+1 , j1 , i2+1 , j2);
        int RR = fn(grid , dp , n , i1 , j1+1 , i2 , j2+1);
        int DR = fn(grid , dp , n , i1+1 , j1 , i2 , j2+1);
        int RD = fn(grid , dp , n , i1 , j1+1 , i2+1 , j2);

        int maxi = max({DD , RR , DR , RD});

        return dp[i1][j1][i2][j2] = (maxi == INT_MIN) ? maxi : maxi + cheries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<vector<int>>>> dp(n , vector<vector<vector<int>>>(n , vector<vector<int>> (n , vector<int>(n , -1))));
        
        int ans = fn(grid , dp , n , 0 , 0 , 0 , 0);
        return ans == INT_MIN ? 0 : ans;
    }
};