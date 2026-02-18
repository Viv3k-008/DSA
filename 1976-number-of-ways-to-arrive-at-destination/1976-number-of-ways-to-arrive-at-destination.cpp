class Solution {
public:
    long long mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(vector<int> e : roads){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> dp(n);
        dp[0] = 1;
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;

        vector<long long> dist(n,1e18);
        dist[0] = 0;

        pq.push({dist[0],0});

        while(!pq.empty()){
            auto it = pq.top();
            int nd = it.second;
            long long w = it.first;

            pq.pop();

            if(dist[nd] != w) continue;

            for(auto it : adj[nd]){
                int nb = it.first;
                int nbW = it.second;

                if(w+nbW < dist[nb]){
                    dist[nb] = w+nbW;
                    dp[nb] = dp[nd];

                    pq.push({dist[nb],nb});
                }
                else if(w+nbW == dist[nb]){
                    dp[nb] = (dp[nb] + dp[nd])%mod;
                }
            }
        }

        return dp[n-1];
    }
};