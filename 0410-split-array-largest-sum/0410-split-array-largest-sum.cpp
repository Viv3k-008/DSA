class Solution {
public:
    int fn(int mid, vector<int>& nums){
        int sum = 0, k = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(sum+nums[i] <= mid){
                sum += nums[i];
            }
            else{
                k++;
                sum = nums[i];
            }
        }
        return k+1;
    }
    int splitArray(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(),nums.end(),0);

        int n = nums.size();

        int st = 0, ed = total, ans = -1;
        for(int i : nums) st = max(st, i);

        while(st <= ed){
            int mid = st+(ed-st)/2;

            if(fn(mid, nums) <= k){
                ans = mid;
                ed = mid-1;
            }
            else st = mid+1;
        }

        return ans;
    }
};