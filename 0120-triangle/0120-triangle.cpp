
// Giving TLE
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> nums;
    int fn(int i , int j , int& n){
        if(i == n-1) return nums[i][j];
        if(dp[i][j] != -1e9) return dp[i][j];

        int op1 = fn(i+1 , j , n) + nums[i][j];
        int op2 = fn(i+1 , j+1 , n) + nums[i][j];

        return dp[i][j] = min(op1 , op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.resize(n , vector<int>(n , -1e9));
        nums = triangle;
        return fn(0 , 0 , n);
    }
};

// Tabulation
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& t) {
//         int n = t.size();
//         vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));

//         for(int i = n-1 ; i >= 0 ; i--){
//             for(int j = t[i].size()-1 ; j >= 0 ; j--){
//                 int op1 = dp[i+1][j] + t[i][j];
//                 int op2 = dp[i+1][j+1] + t[i][j];

//                 dp[i][j] = min(op1 , op2);
//             }
//         }

//         return dp[0][0];
//     }
// };