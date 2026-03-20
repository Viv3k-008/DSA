class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();

        vector<vector<int>> ans(n-k+1 , vector<int>(m-k+1 , 0));

        for(int u = 0 ; u <= n-k ; u++){
            for(int v = 0 ; v <= m-k ; v++){
                vector<int> temp;
                for(int i = u ; i < u+k ; i++){
                    for(int j = v ; j < v+k ; j++){
                        temp.push_back(grid[i][j]);
                    }
                }
                sort(temp.begin(),temp.end());
                int minDiff = INT_MAX;
                for(int i = 0 ; i < temp.size()-1 ; i++){
                    if(temp[i] == temp[i+1]) continue;
                    minDiff = min(minDiff , temp[i+1]-temp[i]);
                }
                ans[u][v] = (minDiff == INT_MAX)? 0 : minDiff;
            }
        }

        return ans;
    }
};