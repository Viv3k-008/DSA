class NumArray {
public:
    vector<int> prefSum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefSum.resize(n,0);
        for(int i = 0 ; i < n ; i++){
            prefSum[i] = (i == 0)? nums[i] : nums[i]+prefSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return (left == 0) ? prefSum[right] : prefSum[right]-prefSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */