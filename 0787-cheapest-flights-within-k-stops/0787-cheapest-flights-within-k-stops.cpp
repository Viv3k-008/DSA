class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // dijkastra's algo

        vector<vector<pair<int,int>>> adj(n);

        for(vector<int> it : flights){
            int u = it[0];
            int v = it[1];
            int p = it[2];

            adj[u].push_back({v,p});
        }

        queue<vector<int>> pq;
        vector<int> dist(n , INT_MAX);
        dist[src] = 0;

        pq.push({src,0,0});

        while(!pq.empty()){
            auto cur = pq.front();
            pq.pop();
            int nd = cur[0];
            int stops = cur[2];
            int cost = cur[1];

            if(stops > k) continue;

            for(pair<int,int> it : adj[nd]){
                int ch = it.first;
                int w = it.second;

                if((w+cost) < dist[ch]){
                    dist[ch] = w+cost;
                    pq.push({ch , dist[ch] , stops+1});
                }
            }
        }


        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};