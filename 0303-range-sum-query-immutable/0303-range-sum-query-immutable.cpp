class NumArray {
public:
    vector<int> prefSum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefSum.resize(n);

        for(int i = 0 ; i < n ; i++){
            prefSum[i] = i == 0? nums[i] : prefSum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left != 0){
            return prefSum[right]-prefSum[left-1];
        }
        else return prefSum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */