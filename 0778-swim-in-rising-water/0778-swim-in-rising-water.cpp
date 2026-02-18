class Solution {
public:
    int inf = 1e9;
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dist(n , vector<int>(m , inf));

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0] , {0 , 0}});
        dist[0][0] = grid[0][0];

        int di[] = {-1 , 1 , 0 , 0};
        int dj[] = {0 , 0 , -1 , 1};

        while(!pq.empty()){
            int time = pq.top().first;
            int curi = pq.top().second.first;
            int curj = pq.top().second.second;
            pq.pop();

            if(curi == n-1 && curj == m-1) return time;
            if(dist[curi][curj] != time) continue;

            for(int i = 0 ; i < 4 ; i++){
                int newi = curi+di[i];
                int newj = curj+dj[i];

                if(newi < 0 || newi >= n || newj < 0 || newj >= m){
                    continue;
                }

                int maxTime = max(time , grid[newi][newj]);

                if(maxTime < dist[newi][newj]){
                    dist[newi][newj] = maxTime;
                    pq.push({maxTime, {newi,newj}});
                }
            }
           
        }

        return -1;
    }
};