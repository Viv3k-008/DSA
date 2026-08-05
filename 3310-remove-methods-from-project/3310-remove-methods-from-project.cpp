class Solution {
public:
    void bfs(int src, int n, vector<bool>& mark, vector<vector<int>>& adj){

        mark[src] = true;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int nb : adj[cur]){
                if(mark[nb]) continue;

                mark[nb] = true;
                q.push(nb);
            }
        }

       
    }
    bool bfs2(int src, int n, vector<bool>& mark, vector<bool>& suspicious, vector<vector<int>>& adj){

        mark[src] = true;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int nb : adj[cur]){
                if(mark[nb]) continue;
                if(suspicious[nb]) return true;

                mark[nb] = true;
                q.push(nb);
            }
        }

       return false;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(vector<int> it : invocations){
            int a = it[0];
            int b = it[1];

            adj[a].push_back(b);
        }

        vector<bool> suspicious(n, false);
        bfs(k, n, suspicious, adj);

        vector<int> ans;
        vector<bool> vis(n, false);

        bool check = false;
        for(int i = 0 ; i < n ; i++){
            if(!suspicious[i] && !vis[i]){
                check = bfs2(i, n, vis, suspicious, adj);
            }

            if(check) break;
        }

        if(check){
            for(int i = 0 ; i < n ; i++) ans.push_back(i);
            return ans;
        }

        for(int i = 0 ; i < n ; i++) if(!suspicious[i]) ans.push_back(i);

        return ans;
    }
};