class Solution {
public:
    bool first(int i , vector<int>& nums){
        for(int j = i+1 ; j < nums.size() ; j++){
            if(nums[j-1] < nums[j]) continue;
            else if(j-i < 2) return false;
            return second(j , nums);
        }
        return false;
    }
    bool second(int i , vector<int>& nums){
        for(int j = i ; j < nums.size() ; j++){
            if(nums[j-1] > nums[j]) continue;
            else if(j-i < 1) return false;
            return third(j , nums);
        }
        return false;
    }
    bool third(int i , vector<int>& nums){
        for(int j = i ; j < nums.size() ; j++){
            if(nums[j-1] < nums[j]){
                continue;
            }
            else return false;
        }
        return true;
    }
    bool isTrionic(vector<int>& nums) {
        if(nums.size() < 4) return false;
        return first(0 , nums);
    }
};