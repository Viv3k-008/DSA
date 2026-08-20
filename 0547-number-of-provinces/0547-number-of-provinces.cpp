class Solution {
public:
    void dfs(int src,  vector<vector<int>>& adj, vector<bool>& vis){
        for(int num : adj[src]){
            if(vis[num]) continue;
            vis[num] = true;
            dfs(num, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                ans++;
            }
        }

        return ans;
    }
};