class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegree(n+1 , 0) , indegree(n+1 , 0);

        for(int i = 0 ; i < trust.size() ; i++){
            int u = trust[i][0];
            int v = trust[i][1];
            outdegree[u]++;
            indegree[v]++;
        }

        int judge = -1;
        for(int i = 1 ; i <= n ; i++){
            if(outdegree[i] == 0 && indegree[i] == n-1){
                judge = i;
            }
        }

        return judge;
    }
};