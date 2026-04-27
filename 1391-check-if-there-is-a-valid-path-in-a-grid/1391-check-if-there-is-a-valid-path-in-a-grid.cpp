class Solution {
public:
    int di[4] = {-1, 1, 0, 0}; // 0: Up, 1: Down, 2: Left, 3: Right
    int dj[4] = {0, 0, -1, 1};

    bool fn(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(i == n - 1 && j == m - 1){
            return true;
        }

        for(int k = 0; k < 4; k++){
            int newi = i + di[k];
            int newj = j + dj[k];

            if(newi < 0 || newj < 0 || newi >= n || newj >= m || vis[newi][newj]){
                continue;
            }

            int flag = grid[i][j];
            int cur = grid[newi][newj];

            // 1. Moving UP (k == 0)
            // Current pipe must open UP. Next pipe must open DOWN.
            bool goUp = (k == 0) && 
                        (flag == 2 || flag == 5 || flag == 6) && 
                        (cur == 2 || cur == 3 || cur == 4);

            // 2. Moving DOWN (k == 1)
            // Current pipe must open DOWN. Next pipe must open UP.
            bool goDown = (k == 1) && 
                          (flag == 2 || flag == 3 || flag == 4) && 
                          (cur == 2 || cur == 5 || cur == 6);

            // 3. Moving LEFT (k == 2)
            // Current pipe must open LEFT. Next pipe must open RIGHT.
            bool goLeft = (k == 2) && 
                          (flag == 1 || flag == 3 || flag == 5) && 
                          (cur == 1 || cur == 4 || cur == 6);

            // 4. Moving RIGHT (k == 3)
            // Current pipe must open RIGHT. Next pipe must open LEFT.
            bool goRight = (k == 3) && 
                           (flag == 1 || flag == 4 || flag == 6) && 
                           (cur == 1 || cur == 3 || cur == 5);

            // If any valid connection is made, explore that path
            if (goUp || goDown || goLeft || goRight) {
                vis[newi][newj] = true;
                
                if (fn(newi, newj, n, m, grid, vis)) {
                    return true; // Stop searching immediately once a path is found
                }
                
                // Note: NO vis[newi][newj] = false here. 
                // Once visited, we never need to visit it again.
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        // Mark the start node as visited!
        vis[0][0] = true; 
        
        return fn(0, 0, n, m, grid, vis);
    }
};