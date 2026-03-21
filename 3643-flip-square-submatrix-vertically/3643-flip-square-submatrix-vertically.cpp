class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = y ; i < y+k ; i++){
            int st = x , ed = min(x+k , (int) grid.size())-1;

            while(st < ed){
                swap(grid[st][i],grid[ed][i]);
                st++ , ed--;
            }
        }

        return grid;
    }
};