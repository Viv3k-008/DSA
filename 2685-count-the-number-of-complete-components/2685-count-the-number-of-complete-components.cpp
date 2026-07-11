class Solution {
public:
    bool bfs(int i, int n, vector<int>& vis, vector<vector<int>>& adj){
        vector<int> cnt(n,0);

        queue<int> q;
        q.push(i);
        vis[i] = true;
        int nodes = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int nb : adj[cur]){
                cnt[nb]++;
                if(vis[nb]) continue;
                nodes++;
                vis[nb] = true;
                q.push(nb);
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(cnt[i] != 0 && cnt[i] != nodes-1){
                return false;
            }
        }

        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,false);

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(bfs(i, n, vis, adj)){
                    ans++;
                }
            }
        }

        return ans;
    }
};