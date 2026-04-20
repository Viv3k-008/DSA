class Solution {
public:
    int fn(int k, vector<int>& nums , int n){

        int oddCnt = 0 , niceSub = 0 , l = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2){
                oddCnt++;
            }

            while(l <= i && oddCnt > k){
                if(nums[l]%2){
                    oddCnt--;
                }
                l++;
            }

            niceSub += (i-l+1);
        }

        return niceSub;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = fn(k , nums , n) - fn(k-1 , nums , n);

        return ans;
    }
};