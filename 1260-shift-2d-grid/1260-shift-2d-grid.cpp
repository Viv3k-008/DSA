class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        while(k--){
            vector<int> nums(n);
            nums[0] = grid[n-1][m-1];
            for(int i = 0 ; i < n-1 ; i++){
                nums[i+1] = grid[i][m-1];
            }

            vector<vector<int>> temp(n, vector<int>(m));
            for(int i = 0 ; i < n ; i++) temp[i][0] = nums[i];

            for(int i = 0 ; i < n ; i++){
                for(int j = 1; j < m ; j++){
                    temp[i][j] = grid[i][j-1];
                }
            }

            grid = temp;
        }


        return grid;
    }
};