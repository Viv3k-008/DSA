class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> dp(n , vector<int>(m,0));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(j == 0) dp[j][i] = matrix[j][i];
                else{
                    if(matrix[j][i] == 0){
                        dp[j][i] = 0;
                    }
                    else dp[j][i] += dp[j-1][i]+1;
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            sort(dp[i].rbegin(),dp[i].rend());
        }

        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                maxi = max(maxi , (j+1)*dp[i][j]);
            }
        }

        return maxi;
    }
};