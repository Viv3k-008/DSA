class Solution {
    vector<vector<int>> tree;
    vector<int> val;
    int cnt , k;

    long long dfs(int c , int p){
       long long sum = val[c];
        for(int v : tree[c]){
            if(v == p) continue;

            sum += dfs(v , c);
        }
        
        if(sum % k == 0){
            cnt++;
            return 0;
        }
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        tree.resize(n);
        val.resize(n);
        val = values;
        this->k = k;
        this->cnt = 0;

        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        dfs(0 , -1);
        return cnt;
    }
};