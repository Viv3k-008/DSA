class Solution {
public:
    int fn(int num){
        int sum = 0;

        while(num){
            sum += num%10;
            num /= 10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            maxi = min(maxi , fn(nums[i]));
        }

        return maxi;
    }
};