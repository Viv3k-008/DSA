class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size() , ans = INT_MAX;
        unordered_map<int,vector<int>> mp;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto it : mp){
            if(it.second.size() >= 3){
                int m = it.second.size();

                for(int z = 0 ; z < m ; z++){
                    if(z+2 < m){
                        int i = it.second[z];
                        int j = it.second[z+1];
                        int k = it.second[z+2];
        
                        int curAns = abs(i-j)+abs(j-k)+abs(k-i);
                        ans = min(ans , curAns);
                    }
                }
            }
        }

        return ans==INT_MAX? -1 : ans;
    }
};