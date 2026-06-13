class Solution {
public:
    int mod = 1e9+7;
    void maxDepth(int cur , int par , int d , vector<vector<int>>& adj , vector<int>& dist, vector<int>& parent){

        dist[cur] = d;
        parent[cur] = par;

        for(int i : adj[cur]){
            if(i == par) continue;

            maxDepth(i , cur , d+1 , adj , dist, parent);
        }
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
    int LOG = 30;
    void binaryLifting(int n , vector<int>& parent , vector<vector<int>>& up){
        for(int i = 1 ; i <= n ; i++){
            up[i][0] = parent[i];
        }

        for(int j = 1 ; j < LOG ; j++){
            for(int i = 1 ; i <= n ; i++){
                if(up[i][j-1] != -1){
                    up[i][j] = up[up[i][j-1]][j-1];
                }
                else up[i][j] = -1;
            }
        }
    }
    int kthAncestor(int x , int k , vector<vector<int>>& up){

        for(int i = 0 ; i < LOG ; i++){
            if(k & (1 << i)){
                x = up[x][i];

                if(x == -1){
                    return -1;
                }
            }
        }

        return x;
    }
    int lca(int u , int v , vector<int>& dist , vector<vector<int>>& up){
        if(dist[u] > dist[v]){
            swap(u , v);
        }

        v = kthAncestor(v , dist[v]-dist[u] , up);

        if(u == v) return u;
        for(int i = LOG-1 ; i >= 0 ; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = edges.size() , n = m+1;
        vector<vector<int>> adj(n+1);
        vector<int> parent(n+1);

        for(int i = 0 ; i < m ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n+1 , 0);

        maxDepth(1 , -1 , 0 , adj , dist , parent);

        vector<vector<int>> up(n+1 , vector<int>(LOG , -1));
       
        binaryLifting(n , parent , up);

        vector<int> ans;
        for(int i = 0 ; i < queries.size() ; i++){
            int u = queries[i][0] , v = queries[i][1];

            int ancestor = lca(u , v , dist , up);
            int depth = dist[u] + dist[v] - 2*dist[ancestor];

            if(depth == 0) {
                ans.push_back(0);
            } else {
                int ways = (int)power(2 , depth - 1);
                ans.push_back(ways);
            }
        }

        return ans;
    }
};