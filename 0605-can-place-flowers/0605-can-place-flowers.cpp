class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> nums = flowerbed;
        int N = nums.size();

        int cnt = 0;
        for(int i = 0 ; i < N ; i++){
            if(nums[i] == 0){
                if((i == 0 || nums[i-1] == 0) && (i == N-1 || nums[i+1] == 0)){
                    nums[i] = 1;
                    cnt++;
                }
            }
        }

        return cnt >= n;
    }
};