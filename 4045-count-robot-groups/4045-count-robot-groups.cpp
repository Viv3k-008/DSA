class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();

        vector<int> nums;    // Reducing on the basis of the distance
        for(int i = 0 ; i < n ; i++){
            if(i > 0 && (position[i] - position[i-1]) <= distance){
                nums.pop_back();
            }
            nums.push_back(speed[i]);
        }
        
        int ans = 0, minSpeed = 1e9;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] <= minSpeed){
                minSpeed = nums[i];
                ans++;
            }
        }

        return ans;
    }
};