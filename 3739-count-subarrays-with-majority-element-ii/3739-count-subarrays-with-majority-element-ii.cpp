class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        
        int n = nums.size();

        long long validLeftPts = 0 , cumSum = 0 , result = 0;

        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == target){
                validLeftPts += mp[cumSum];
                cumSum ++;
            }
            else {
                cumSum --;
                validLeftPts -= mp[cumSum];
            }

            mp[cumSum] ++;
            result += validLeftPts;
        }

        return result;
    }
};