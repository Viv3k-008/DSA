class Solution {
public:
    int di[4] = {-1 , 1 , 0 , 0};
    int dj[4] = {0 , 0 , -1 , 1};
    void dfs(int i , int j , int n , int m , vector<vector<char>>& grid , vector<vector<bool>>& vis){

        for(int k = 0 ; k < 4 ; k++){
            int newi = i+di[k];
            int newj = j+dj[k];

            if(newi < 0 || newj < 0 || newi >= n || newj >= m || vis[newi][newj] || grid[newi][newj] == '0'){
                continue;
            }

            vis[newi][newj] = true;
            dfs(newi , newj , n , m , grid , vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == false && grid[i][j] == '1'){
                    cnt++;
                    vis[i][j] = true;
                    dfs(i , j , n , m , grid , vis);
                }
            }
        }

        return cnt;
    }
};