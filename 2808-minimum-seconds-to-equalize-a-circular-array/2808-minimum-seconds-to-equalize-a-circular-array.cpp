class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]].push_back(i);
        }


        int ans = INT_MAX;
        for(auto it : mp){
            vector<int> temp = it.second;

            int t = INT_MIN;
            for(int i = 0 ; i < temp.size()-1; i++){
                int diff = temp[i+1]-temp[i];
                t = max(t, (int)ceil(diff/2));
            }

            int diff = n-temp.back() + temp[0];
            t = max(t, (int)ceil(diff/2));

            ans = min(ans, t);

        }

        return ans;
    }
};