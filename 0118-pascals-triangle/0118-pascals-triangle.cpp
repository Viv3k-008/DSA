class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;

        vector<vector<int>> ans;

        for(int i = 1 ; i <= n ; i++){
            vector<int> row;

            for(int j = 0 ; j < i ; j++){
                if(j == 0 || j == i-1){
                    row.push_back(1);
                    continue;
                }
                else row.push_back(ans[i-2][j-1]+ans[i-2][j]); 
            }
            ans.push_back(row);
        }

        return ans;
    }
};