class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> xcnt(n , vector<int>(m , 0)) , ycnt(n , vector<int>(m , 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0){
                    if(i == 0 && j == 0){
                        if(grid[i][j] == 'X'){
                            xcnt[i][j]++;
                        }
                        else if(grid[i][j] == 'Y'){
                            ycnt[i][j]++;
                        }
                    }
                    else{
                        xcnt[i][j] += xcnt[i][j-1];
                        ycnt[i][j] += ycnt[i][j-1];
                        if(grid[i][j] == 'X'){
                            xcnt[i][j]++;
                        }
                        else if(grid[i][j] == 'Y'){
                            ycnt[i][j]++;
                        }
                    }
                    continue;
                }
                if(j == 0){
                    xcnt[i][j] += xcnt[i-1][j];
                    ycnt[i][j] += ycnt[i-1][j];
                    if(grid[i][j] == 'X'){
                      xcnt[i][j]++;
                    }
                    else if(grid[i][j] == 'Y'){
                        ycnt[i][j]++;
                    }
                    continue;
                }

                xcnt[i][j] += xcnt[i-1][j];
                ycnt[i][j] += ycnt[i-1][j];
                xcnt[i][j] += xcnt[i][j-1];
                ycnt[i][j] += ycnt[i][j-1];

                xcnt[i][j] -= xcnt[i-1][j-1];
                ycnt[i][j] -= ycnt[i-1][j-1];

                if(grid[i][j] == 'X'){
                    xcnt[i][j]++;
                }
                else if(grid[i][j] == 'Y'){
                    ycnt[i][j]++;
                }
               
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(xcnt[i][j] > 0){
                    if(xcnt[i][j] == ycnt[i][j]){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};