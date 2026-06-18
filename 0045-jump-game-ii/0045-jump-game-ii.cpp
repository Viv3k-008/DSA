class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1) return 0;

        int end = 0 , maxRange = 0 , steps = 0;

        for(int i = 0 ; i < n ; i++){
            maxRange = max(maxRange , i+nums[i]);

            if(i == end){
                steps++;
                end = maxRange;
            }

            if(end >= n-1){
                break;
            }
        }

        return steps;
    }
};