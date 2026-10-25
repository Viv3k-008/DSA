class Solution {
public:
    bool bfs(vector<vector<int>> &grid, vector<vector<bool>>& vis, int n, int m, int curi, int curj){
        queue<pair<int,int>> q;
        vis[curi][curj] = true;
        q.push({curi,curj});

        bool flag = true;

        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};
        while(!q.empty()){
            auto it = q.front();
            int i = it.first;
            int j = it.second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int newi = di[k]+i;
                int newj = dj[k]+j;
                if(newi >= n || newj >= m || newi < 0 || newj < 0){
                    flag = false;
                    continue;
                }
                if(grid[newi][newj] == 1 || vis[newi][newj]) continue;
                vis[newi][newj] = true;
                q.push({newi,newj});
            }
        }

        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    bool flag = bfs(grid, vis, n, m , i, j);
                    if(flag) ans++;
                }
            }
        }


        return ans;
    }
};