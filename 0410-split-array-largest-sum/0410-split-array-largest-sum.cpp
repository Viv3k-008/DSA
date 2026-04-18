class Solution {
public:
    int check(vector<int>& nums , int cap){
        int curSum = 0 , cuts = 0 , n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if((curSum + nums[i]) <= cap){
                curSum += nums[i];
            }
            else {
                cuts++;
                curSum = nums[i];
            }
        }

        return cuts+1;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int left = INT_MIN , right = 0;

        for(int i : nums){
            left = max(left , i);
            right += i;
        }


        int ans = -1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(check(nums , mid) <= k){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }

        return ans;
    }
};