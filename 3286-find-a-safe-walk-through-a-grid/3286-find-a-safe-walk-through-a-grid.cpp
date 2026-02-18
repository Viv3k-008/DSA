class Solution {
public:
    int inf = 1e9;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n , vector<int>(m , inf));
        dist[0][0] = grid[0][0];

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

        pq.push({dist[0][0],{0,0}});

        int di[] = {-1 , 1 , 0 , 0};
        int dj[] = {0 , 0 , -1 , 1};

        while(!pq.empty()){
            int curi = pq.top().second.first;
            int curj = pq.top().second.second;
            int curHealth = pq.top().first;
            pq.pop();

            for(int k = 0 ; k < 4 ; k++){
                int newi = curi+di[k];
                int newj = curj+dj[k];

                if(newi < 0 || newj < 0 || newi >= n || newj >= m){
                    continue;
                }
                if(curHealth + grid[newi][newj] < dist[newi][newj]){
                    dist[newi][newj] = curHealth+grid[newi][newj];
                    pq.push({dist[newi][newj],{newi,newj}});
                }
            }
        }

        int reqHealth = dist[n-1][m-1];
        if(reqHealth < health) return true;
        else return false;
    }
};