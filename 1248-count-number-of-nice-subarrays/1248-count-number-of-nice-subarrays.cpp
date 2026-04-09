class Solution {
public:
    int calc(vector<int>& nums , int k){
        int n = nums.size();

        int l = 0 , ans = 0 , cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]%2){
                ans++;
            } 

            while(l <= i && ans > k){
                if(nums[l++]%2){
                    ans--;
                }
            }

            cnt += (i-l+1);

        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        int ans = calc(nums , k) - calc(nums , k-1);

        return ans;
    }
};