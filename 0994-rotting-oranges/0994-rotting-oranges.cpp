class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};

        int ans = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int newi = it.first.first+di[k];
                int newj = it.first.second+dj[k];

                if(newi < 0 || newi >= n || newj < 0 || newj >= m || grid[newi][newj] != 1){
                    continue;
                }

                grid[newi][newj] = 2;
                ans = max(ans, it.second+1);
                q.push({{newi,newj},it.second+1});
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }
};