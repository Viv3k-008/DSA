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
            if(!success){
                return vector<int> {};
            }
        }
        // reverse(ans.begin() , ans.end());
        return ans;
    }

    bool dfs(int cur , vector<int>& vis , vector<int>& ans){
        vis[cur] = 1;

        // go to neighbours and stuff first
        for(int nb : adj[cur]){

            if(vis[nb] == 0){    // vis[nb] -> 0 , tree edge
                bool success = dfs(nb , vis , ans);
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
        ans.push_back(cur);
        return true;
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