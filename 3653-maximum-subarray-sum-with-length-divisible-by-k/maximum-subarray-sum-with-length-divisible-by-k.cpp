class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        map<int,set<long long>> mp;

        long long sum = 0 , ans = LLONG_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];

            int rem = (i)%k;
            if(mp.find(rem) != mp.end()){
                ans = max(ans , sum - *mp[rem].begin());
            }
            mp[rem].insert(sum);
        }
        mp.clear();
        sum = 0;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            sum += nums[i];

            int rem = (i)%k;
            if(mp.find(rem) != mp.end()){
                ans = max(ans , sum - *mp[rem].begin());
            }
            mp[rem].insert(sum);
        }
        if(nums.size()%k == 0){
            ans = max(ans , sum);
        }
        return ans;
    }
};