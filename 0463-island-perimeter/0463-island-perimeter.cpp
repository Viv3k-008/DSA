class Solution {
public:
    int dfs(int curi , int curj , vector<vector<int>>& grid , vector<vector<bool>>& vis){
       
        int di[] = {1 , -1 , 0 , 0};
        int dj[] = {0 , 0 , -1 , 1};

        int sum = 0;
        for(int i = 0 ; i < 4 ; i++){
            int newi = curi + di[i];
            int newj = curj + dj[i];

            if(newi < 0 || newi >= grid.size() || newj < 0 || newj >= grid[0].size() || grid[newi][newj] == 0){
                sum += 1;
                continue;
            }
            else if(vis[newi][newj] == true){
                continue;
            }
            else {
                vis[newi][newj] = true;
                sum += dfs(newi , newj , grid , vis);
            }

        }

        return sum;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vis[i][j] = true;
                    ans += dfs(i , j , grid , vis);
                }
            }
        }

        return ans;
    }
};