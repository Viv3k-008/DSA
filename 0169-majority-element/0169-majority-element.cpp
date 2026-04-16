class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int ele = -1 , cnt = 0;

        for(int i = 0 ; i < n ; i++){
            if(ele == nums[i]){
                cnt++;
            }
            else if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            }
            else cnt--;
        }

        return ele;
    }
};