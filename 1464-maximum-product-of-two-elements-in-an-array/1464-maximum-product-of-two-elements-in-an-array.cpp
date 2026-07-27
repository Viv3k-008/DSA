class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int firstMax = INT_MIN, secondMax = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > firstMax){
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if(nums[i] > secondMax){
                secondMax = nums[i];
            }
        }

        return (int)(firstMax-1)*(secondMax-1);
    }
};