class Solution {
public:
    int n;
    vector<vector<int>> adj;

    void topoUsingDfs(vector<int>& vis){

        for(int i = 0 ; i < n ; i++){
            if(vis[i] > 0){
                continue;
            }
            bool success = dfs(i , vis);
            if(!success){
                continue;
            }
        }
    }

    bool dfs(int cur , vector<int>& vis){
        vis[cur] = 1;

        // go to neighbours and stuff first
        for(int nb : adj[cur]){

            if(vis[nb] == 0){    // vis[nb] -> 0 , tree edge
                bool success = dfs(nb , vis);
                if(!success){
                    return false;
                }
            }
            else if(vis[nb] == 1){  // vis[nb] -> 1 , means their is a back edge
                return false;
            }
            //do nothing when vis[nb] -> 2 , forward edge or a cross edge
        }


        vis[cur] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        adj.resize(n);

        for(int i = 0 ; i < n ; i++){
            for(int nd : graph[i]){
                adj[i].push_back(nd);
            }
        }
        vector<int> vis(n , 0);
        topoUsingDfs(vis);

        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};