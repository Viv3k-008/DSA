class Solution {
public:
    int fn(int i , int xr , vector<int>& nums){
        if(i == nums.size()){
            return xr;
        }


        int op1 = fn(i+1 , xr^nums[i] , nums);
        int op2 = fn(i+1 , xr , nums);

        return op1+op2;
    }
    int subsetXORSum(vector<int>& nums) {
        
        return fn(0 , 0 , nums);
    }
};