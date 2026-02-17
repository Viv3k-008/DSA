class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(vector<int> nb : times){
            int u = nb[0];
            int v = nb[1];
            int w = nb[2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(n+1 , 1e8);
        dist[k] = 0;

        pq.push({dist[k] , k});

        while(!pq.empty()){
            int cur = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if(dist[cur] != w) continue;

            for(auto it : adj[cur]){
                int nb = it.first;
                int nbW = it.second;

                if(dist[cur]+nbW < dist[nb]){
                    dist[nb] = dist[cur]+nbW;

                    pq.push({dist[nb] , nb});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == 1e8){
                return -1;
            }
            maxi = max(maxi , dist[i]);
        }

        return maxi;
    }
};