class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2) return nums;


        vector<int> arr1, arr2;

        int i = 0;
        arr1.push_back(nums[i++]);
        arr2.push_back(nums[i++]);

        while(i < n){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);

            i++;
        }

        int k = arr1.size();
        for(int i = 0 ; i < n ; i++){
            if(i < k) nums[i] = arr1[i];
            else nums[i] = arr2[i-k];
        }

        return nums;
    }
};