class Solution {
public:
    int minRemoval(vector<int>& num, int k) {
        int n = num.size();
        if(n == 1) return 0;

        vector<long long> nums(num.begin(),num.end());
        sort(nums.begin(),nums.end());

        int i = 0 , j = i+1 , ans = 0;

        while(j < n){
            if((long long)nums[i]*k >= nums[j]){
                ans = max(ans , j-i+1);
                j++;
            }
            else i++;
        }

        return (ans == 0)? 0 : n-ans;
    }
};