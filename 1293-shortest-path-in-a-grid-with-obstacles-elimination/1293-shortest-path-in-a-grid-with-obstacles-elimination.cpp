class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();

        vector<vector<vector<int>>> dist(n , vector<vector<int>>(m , vector<int>(k+1 , -1)));
        queue<vector<int>> q;
        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};
        q.push({0,0,k});
        dist[0][0][k] = 0;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            int curi = cur[0];
            int curj = cur[1];
            int curk = cur[2];

            if(curi == n-1 && curj == m-1 && curk >= 0) return dist[curi][curj][curk];

            for(int k = 0 ; k < 4 ; k++){
                int newi = di[k]+curi;
                int newj = dj[k]+curj;

                if(newi < 0 || newj < 0 || newi >= n || newj >= m || (curk-grid[newi][newj]) < 0) continue;

                int newk = curk-grid[newi][newj];
                if(dist[newi][newj][newk] != -1) continue;

                dist[newi][newj][newk] = dist[curi][curj][curk]+1;
                q.push({newi,newj,newk});
            }
        }

        return -1;
    }
};