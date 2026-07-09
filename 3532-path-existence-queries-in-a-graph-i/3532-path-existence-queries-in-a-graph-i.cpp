class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> id(n);
        for(int i = 0 ; i < n ; i++) id[i] = i;

        int l = 0, r = 1;
        while(r < n){
            if(l == r){
                r++;
            }
            else{
                if((nums[r]-nums[l]) <= maxDiff){
                    id[r] = id[l];
                    r++;
                }
                else l++;
            }
        }

        vector<bool> ans;
        int m = queries.size();

        for(int i = 0 ; i < m ; i++){
            int l = queries[i][0], r = queries[i][1];
            if(id[l] == id[r]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;
    }
};