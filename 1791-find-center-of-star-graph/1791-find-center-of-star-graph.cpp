class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;

        vector<int> indegree(n+1 , 0);

        for(int i = 0 ; i < n-1 ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[u]++;
            indegree[v]++;
        }

        for(int i = 1 ; i <= n ; i++){
            if(indegree[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};