class Solution {
public:
    bool sumGame(string nums) {
        int n = nums.size();

        int leftSum = 0, rightSum = 0, leftk = 0, rightk = 0;

        for(int i = 0 ; i < n ; i++){
            if(i < n/2){
                if(nums[i] == '?'){
                    leftk++;
                }
                else leftSum += nums[i]-'0';
            }
            else {
                if(nums[i] == '?'){
                    rightk++;
                }
                else rightSum += nums[i]-'0';
            }
        }

        int totalk = leftk+ rightk;
        if(totalk%2) return true;

        int left = 2*leftSum + 9*leftk;
        int right = 2*rightSum + 9*rightk;
        

        return !(left == right);
    }
};