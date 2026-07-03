class Solution {
public:
    bool check(int mini, int n, vector<vector<pair<int,int>>>& adj, long long k){
        priority_queue<vector<long long>, vector<vector<long long>> , greater<vector<long long>>> pq;
       
        pq.push({0,0});
        vector<long long> dist(n,LLONG_MAX);
        dist[0] = 0;

        int pathMin = INT_MAX;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            long long curNd = cur[1];
            long long curSum = cur[0];

            if(curSum != dist[curNd]) continue;

            for(auto it : adj[curNd]){
                int nb = it.first;
                int w = it.second;

                if(1LL*(curSum+w) < dist[nb] && mini <= w){
                    dist[nb] = 1LL*(curSum+w);
                    pq.push({curSum+w,nb});
                }
            }
        }

        return dist[n-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size() , m = edges.size() , maxi = INT_MIN;

        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i < m ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            maxi = max(maxi , w);
            if(online[u] && online[v]){
                adj[u].push_back({v,w});
            }
        }

        long long l = 0 , r = maxi , ans = -1;
        while(l <= r){
            long long mid = l+(r-l)/2;

            if(check(mid, n, adj, k)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }

        return (int)ans;
    }
};