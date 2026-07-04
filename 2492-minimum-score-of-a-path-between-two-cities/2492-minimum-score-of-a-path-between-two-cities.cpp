class Solution {
public:
    void dfs(int cur , vector<bool>& vis , int& mini ,vector<vector<pair<int,int>>>& adj){

        for(auto it : adj[cur]){
            int nb = it.first;
            int w = it.second;

            mini = min(mini , w);

            if(vis[nb]) continue;
            vis[nb] = true;
            dfs(nb , vis , mini , adj);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();

        vector<vector<pair<int,int>>> adj(n+1);

        for(int i = 0 ; i < m ; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<bool> vis(n+1 , false);
        int mini = INT_MAX;
        dfs(1 , vis , mini , adj);

        return mini;
    }
};