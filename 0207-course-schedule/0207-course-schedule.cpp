class Solution {
public:

    bool dfs(vector<int>& courses , vector<vector<int>>& adj , int cur){
        courses[cur] = 1;

        for(int nb : adj[cur]){
    
            if(courses[nb] == 1){
                return true;
            }
            else if(courses[nb] == 2){
                continue;
            }

            if(dfs(courses , adj , nb)){
                return true;
            }
        }

        courses[cur] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> courses(n , 0);

        vector<vector<int>> adj(n);

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }


        for(int i = 0 ; i < n ; i++){
            if(courses[i] == 0){
                bool check = dfs(courses , adj , i);

                if(check){
                    return false;
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(courses[i] == 1){
                return false;
            }
        }

        return true;
    }
};