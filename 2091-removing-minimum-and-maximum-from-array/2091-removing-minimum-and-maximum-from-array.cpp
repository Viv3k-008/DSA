class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        pair<int,int> num = {-1e9,1e9};
        for(int i : nums){
            num.first = max(num.first,i);
            num.second = min(num.second,i);
        }

        int ways = 1e9;
        pair<int,int> idx = {-1,-1};
        // left to right
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num.first){
                idx.first = i;
            }
            else if(nums[i] == num.second){
                idx.second = i;
            }
            if(idx.first != -1 && idx.second != -1) break;
        }
        int l = min(idx.first,idx.second);
        int r = max(idx.first,idx.second);
        ways = min({r+1, n-l, l+1+n-r});


        return ways;
    }
};