class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size() , m = grid[0].size();

        int di[4] = {1, -1, 0, 0};
        int dj[4] = {0, 0, -1, 1};

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dp(n , vector<int>(m , -1e9));

        q.push({health-grid[0][0],{0,0}});
        dp[0][0] = health-grid[0][0];

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int h = it.first;
            int curi = it.second.first;
            int curj = it.second.second;

            if(curi == n-1 && curj == m-1 && h >= 1) return true;

            for(int k = 0 ; k < 4 ; k++){
                int newi = curi+di[k];
                int newj = curj+dj[k];

                if(newi < 0 || newi >= n || newj < 0 || newj >= m || (h-grid[newi][newj]) < 1 || (h-grid[newi][newj]) <= dp[newi][newj]){
                    continue;
                }
                dp[newi][newj] = h-grid[newi][newj];
                q.push({dp[newi][newj],{newi,newj}});
            }
        }

        return false;
    }
};