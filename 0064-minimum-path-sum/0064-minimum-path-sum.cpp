class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        
        vector<int> next(m+1 , 1e9) , cur(m+1 , 1e9);

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                
                if(i == n-1 && j == m-1){
                    cur[j] = grid[i][j];
                    continue;
                }

                int mini = min(next[j] , cur[j+1]);
                cur[j] = mini + grid[i][j];

            }
            next = cur;
        }

        return next[0];
    }
};