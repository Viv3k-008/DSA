class Solution {
public:
    int n , m;
    vector<vector<vector<int>>> dp;
    int fn(int i , int j , vector<vector<int>>& grid , int k){
        if(i == n-1 && j == m-1){
            if(grid[i][j] < 0 && k > 0) return dp[i][j][k] = 0;
            else return dp[i][j][k] = grid[i][j];
        }

        if(i >= n || j >= m) return INT_MIN;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        // to go down
        int tempDown = INT_MIN , down = INT_MIN;

        if(i+1 < n) tempDown = fn(i+1 , j , grid , k);

        if(i+1 < n && grid[i][j] < 0 && k > 0){

           down = fn(i+1 , j , grid , k-1);

           if(tempDown != INT_MIN){
               down = max(down , tempDown + grid[i][j]);
           }

        }
        else if(tempDown != INT_MIN){
            down = tempDown + grid[i][j];
        }
        

        // to go right
        int tempRight = INT_MIN , right = INT_MIN;

        if(j+1 < m) tempRight = fn(i , j+1 , grid , k);
       
        if(j+1 < m && grid[i][j] < 0 && k > 0){

            right = fn(i , j+1 , grid , k-1);

            if(tempRight != INT_MIN){
                right = max(right , tempRight+grid[i][j]);
            }

        }
        else if(tempRight != INT_MIN){
            right = tempRight + grid[i][j];
        }

        return dp[i][j][k] = max(down , right);
    }
    int maximumAmount(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();

        dp.assign(n , vector<vector<int>>(m , vector<int>(4 , -1)));

        // int ans = fn(0 , 0 , coins , 2);

        // return ans;

        for(int k = 0; k <= 2; k++){
            if(grid[n-1][m-1] < 0 && k > 0)
                dp[n-1][m-1][k] = 0;
            else
                dp[n-1][m-1][k] = grid[n-1][m-1];
        }

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                if(i == n-1 && j == m-1) continue;

                for(int k = 0 ; k <= 2 ; k++){

                    // to go down
                    int tempDown = INT_MIN , down = INT_MIN;

                    if(i+1 < n) tempDown = dp[i+1][j][k];

                    if(i+1 < n && grid[i][j] < 0 && k > 0){

                    down = dp[i+1][j][k-1];

                    if(tempDown != INT_MIN){
                        down = max(down , tempDown + grid[i][j]);
                    }

                    }
                    else if(tempDown != INT_MIN){
                        down = tempDown + grid[i][j];
                    }

                    // to go right
                    int tempRight = INT_MIN , right = INT_MIN;

                    if(j+1 < m) tempRight = dp[i][j+1][k];
                
                    if(j+1 < m && grid[i][j] < 0 && k > 0){

                        right = dp[i][j+1][k-1];

                        if(tempRight != INT_MIN){
                            right = max(right , tempRight+grid[i][j]);
                        }

                    }
                    else if(tempRight != INT_MIN){
                        right = tempRight + grid[i][j];
                    }

                    dp[i][j][k] = max(down , right);
                }
            }
        }


        return dp[0][0][2];
    }
};