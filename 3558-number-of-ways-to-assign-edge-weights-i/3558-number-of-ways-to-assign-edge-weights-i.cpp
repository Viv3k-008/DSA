class Solution {
public:
    int mod = 1e9+7;
    int maxDepth(int cur , int par , vector<vector<int>>& adj){
       
        int curLen = 0;
        for(int i : adj[cur]){
            if(i == par) continue;

            curLen = max(1+maxDepth(i , cur , adj) , curLen);
        }

        return curLen;
    }
    long long power(int num , int depth){
        if(depth <= 0){
            return 1;
        }

        long long half = power(num , depth/2);

        half = (half*half)%mod;

        if(depth%2){
            half = (half*num)%mod;
        }

        return half;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int m = edges.size() , n = m+1;
        vector<vector<int>> adj(n+1);

        for(int i = 0 ; i < m ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = maxDepth(1 , -1 , adj);

        long long totalWays = power(2 , depth-1);

        return (int)totalWays%mod;
    }
};