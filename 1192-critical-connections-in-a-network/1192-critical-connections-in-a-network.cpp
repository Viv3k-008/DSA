class Solution {
public:
    int timer = 0;
    void dfs(int node , int par , vector<bool>& vis , vector<vector<int>>& adj , vector<int>& tin , vector<int>& low , vector<vector<int>>& bridges){
        tin[node] = low[node] = timer++;

        for(int nd : adj[node]){
            if(nd == par) continue;

            if(vis[nd]){
                low[node] = min(low[nd] , low[node]);
            }
            else {
                vis[nd] = true;
                dfs(nd , node , vis , adj , tin , low , bridges);

                low[node] = min(low[nd] , low[node]);

                // Now check for bridge
                if(low[nd] > tin[node]){
                    bridges.push_back({node , nd});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(vector<int> it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> tin(n);  // time of insertion
        vector<int> low(n);  // lowest time to reach this node

        vector<vector<int>> bridges;
        vector<bool> vis(n , false);
        vis[0] = true;
        dfs(0 , -1 , vis , adj , tin , low , bridges);

        return bridges;
    }
};