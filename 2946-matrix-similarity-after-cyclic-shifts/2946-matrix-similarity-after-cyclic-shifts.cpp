class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size() , m = mat[0].size();
        k = k%m;
        vector<vector<int>> grid = mat;

       
        for(int i = 0 ; i < n ; i++){
            if(i%2){
                reverse(grid[i].begin(),grid[i].begin()+k);
                reverse(grid[i].begin()+k,grid[i].end());
                reverse(grid[i].begin(),grid[i].end());
            }
            else {
               vector<int> last , first;
               for(int j = 0 ; j < m ; j++){
                if(j <= k-1){
                    last.push_back(grid[i][j]);
                }
                else first.push_back(grid[i][j]);
               }
               for(int i : last){
                first.push_back(i);
               }
               grid[i] = first;
            }
        }
       

        if(grid == mat) return true;
        else return false;
    }
};