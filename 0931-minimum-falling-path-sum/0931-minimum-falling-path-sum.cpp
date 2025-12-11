class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i , int j , vector<vector<int>>& mat){
        if(i == mat.size()){
            return 0;
        }

        if(i < 0 || j < 0 || j >= mat[0].size()){
            return INT_MAX;
        }

        if(dp[i][j] != -1e9) return dp[i][j];

        int down = fn(i+1 , j , mat);
        int diagLeft = fn(i+1 , j-1 , mat);
        int diagRight = fn(i+1 , j+1 , mat);

        return dp[i][j] = min({down , diagLeft , diagRight}) + mat[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size() , ans = INT_MAX;
        dp.resize(n , vector<int>(n , -1e9));
        for(int i = 0 ; i < n ; i++){
            ans = min(ans , fn(0 , i , matrix));
        } 

        return ans;
    }
};