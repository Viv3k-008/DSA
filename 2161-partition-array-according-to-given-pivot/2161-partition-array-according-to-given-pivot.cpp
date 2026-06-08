class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left , right;
        int n = nums.size() , cnt = 0 , pos = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < pivot){
                left.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                right.push_back(nums[i]);
            }
            else cnt++;
        }
        // copy to ans vector
        int N = left.size() + right.size() + cnt;
        vector<int> ans(N);
        for(int i = 0 ; i < left.size() ; i++) ans[i] = left[i];
        for(int i = 0 ; i < cnt ; i++) ans[left.size()+i] = pivot;
        for(int i = 0 ; i < right.size() ; i++) ans[left.size() + cnt + i] = right[i];

        return ans; 
    }
};