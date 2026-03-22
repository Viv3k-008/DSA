class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size() , m = mat[0].size();

        int k = 4;
        
        while(k--){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0  ; j < m ; j++){
                    if(i < j){
                        swap(mat[i][j],mat[j][i]);
                    }
                }
            }

            for(int i = 0 ; i < n ; i++){
                reverse(mat[i].begin(),mat[i].end());
            }

            if(mat == target) return true;
        }

        return false;
    }
};