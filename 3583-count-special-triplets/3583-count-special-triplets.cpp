class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        int mod = 1e9+7;
        unordered_map<int,int> pref , suff;

        pref[nums[0]]++;

        for(int i : nums) suff[i]++;

        suff[nums[0]]--;
        if(suff[nums[0]] == 0){
            suff.erase(nums[0]);
        }

        for(int i = 0 ; i < n ; i++){
            if(i == 0 || i == n-1) continue;

            suff[nums[i]]--;
            if(suff[nums[i]] == 0){
                suff.erase(nums[i]);
            }

            int doubleVal = nums[i]*2;
            cnt = (cnt + (long long) pref[doubleVal] * suff[doubleVal])%mod;
            pref[nums[i]]++;
        }

        return (int)cnt;
    }
};