class NumMatrix {
public:
    vector<vector<int>> prefMat;
    int n , m;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        prefMat.resize(n , vector<int>(m , 0));
    
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                int newi = i+1 , newj = j+1 , sum = matrix[i][j];
                if(newi < n){
                    sum += prefMat[newi][j];
                }
                if(newj < m){
                    sum += prefMat[i][newj];
                }
                if(newi < n && newj < m){
                    sum -= prefMat[newi][newj];
                }
                
                prefMat[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefMat[row1][col1];
        if(col2+1 < m){
            sum -= prefMat[row1][col2+1];
        }
        if(row2+1 < n){
            sum -= prefMat[row2+1][col1];
        }
        if(col2+1 < m && row2+1 < n){
            sum += prefMat[row2+1][col2+1];
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */