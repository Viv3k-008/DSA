class Solution {
public:
    static bool comp(vector<int>& vec1 , vector<int>& vec2){
        return vec1[0] < vec2[0];
    }

    int bs(vector<vector<int>>& nums , int l , int end){
        int r = nums.size()-1;

        int next = -1;
        while(l <= r){
            int mid = l+(r-l)/2;

            if(nums[mid][0] >= end){
                next = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        return next;
    }

    int fn(int i , vector<vector<int>>& nums , vector<int>& dp){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int next = bs(nums , i , nums[i][1]);
        int taken = nums[i][2] + fn(next , nums , dp);

        int notTaken = fn(i+1 , nums , dp);

        return dp[i] = max(taken , notTaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> nums(n , vector<int>(3 , 0));

        for(int i = 0 ; i < n ; i++){
            nums[i][0] = startTime[i];
            nums[i][1] = endTime[i];
            nums[i][2] = profit[i];
        }

        sort(nums.begin() , nums.end() , comp);

        vector<int> dp(n , -1);

        return fn(0 , nums , dp);
    }
};