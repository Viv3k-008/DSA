class Solution {
public:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    void multiSrcBfs(vector<vector<int>>& grid , vector<vector<int>>& thiefDist){
        int n = grid.size() , m = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    thiefDist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            int curi = cur.first;
            int curj = cur.second;

            for(int k = 0 ; k < 4 ; k++){
                int newi = curi+di[k];
                int newj = curj+dj[k];

                if(newi < 0 || newi >= n || newj < 0 || newj >= m || thiefDist[newi][newj] != -1){
                    continue;
                }

                thiefDist[newi][newj] = thiefDist[curi][curj]+1;

                q.push({newi,newj});
            }
        }
    }
    bool check(vector<vector<int>>& thiefDist ,int minDist, int i , int j , int n , int m){
        if(thiefDist[0][0] < minDist) return false;
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n , vector<bool>(m , false));

        q.push({0,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int curi = it.first;
            int curj = it.second;
            if(curi == n-1 && curj == m-1) return true;

            for(int k = 0 ; k < 4 ; k++){
                int newi = curi+di[k];
                int newj = curj+dj[k];

                if(newi < 0 || newj < 0 || newi >= n || newj >= m || vis[newi][newj] || thiefDist[newi][newj] < minDist){
                    continue;
                }
                vis[newi][newj] = true;

                q.push({newi,newj});
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;

        vector<vector<int>> thiefDist(n , vector<int>(m , -1));
        multiSrcBfs(grid , thiefDist);

        

        int low = 0 , high = n*m , ans = -1;

        while(low <= high){
            int mid = low+(high-low)/2;
            
            if(check(thiefDist, mid, 0, 0, n, m)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;
    }
};