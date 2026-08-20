class Solution {
public:
    bool fn(int i, vector<vector<int>>& graph, vector<int>& vis, bool c){

        for(int nd : graph[i]){
            if(vis[nd] == c){
                return false;
            }
            if(vis[nd] == !c) continue;
            if(vis[nd] == -1){
                vis[nd] = !c;
                if(!fn(nd, graph, vis, !c)){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, -1);

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(!fn(i, graph, vis, 0)){
                    return false;
                }
            }
        }

        return true;
    }
};