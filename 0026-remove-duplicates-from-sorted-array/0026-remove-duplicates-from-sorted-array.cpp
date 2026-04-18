class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int l = 1 , num = nums[0];

        for(int i = 1 ; i < n ; i++){
            if(nums[i] != num){
                num = nums[i];
                swap(nums[i] , nums[l++]);
            }
        }

        return l;
    }
};