class Solution {
public:
    int n;
    vector<vector<int>> adj;

    vector<int> topoUsingDfs(){
        vector<int> vis(n , 0);  // initial state  -> 0
        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            if(vis[i] > 0){
                continue;
            }
            bool success = dfs(i , vis , ans);
            if(success){
                return vector<int> {};
            }
        }
        return ans;
    }

    bool dfs(int cur , vector<int>& vis , vector<int>& ans){

        for(int nb : adj[cur]){
            if(vis[nb] == 1) return true;
            if(vis[nb] == 2) continue;

            vis[nb] = 1;
            if(dfs(nb, vis, ans)){
                return true;
            }
        }


        vis[cur] = 2;
        ans.push_back(cur);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        adj.resize(n);

        for(vector<int> it : prerequisites){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
        }
        return topoUsingDfs();
    }
};