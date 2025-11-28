class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        map<int,set<long long>> mp;
        mp[0].insert(0);
        long long sum = 0 , ans = LLONG_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];

            int rem = (i+1)%k;
            if(mp.find(rem) != mp.end()){
                ans = max(ans , sum - *mp[rem].begin());
            }
            mp[rem].insert(sum);
        }
        return ans;
    }
};