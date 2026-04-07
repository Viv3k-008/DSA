class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<vector<int>> nums(n , vector<int>(2 , 0));

        for(int i = 0 ; i < n ; i++){
            nums.push_back({growTime[i] , plantTime[i]});
        }

        sort(nums.rbegin(),nums.rend());

        int maxTime = INT_MIN , time = 0;
        for(int i = 0 ; i < n ; i++){
            time += nums[i][1];
            maxTime = max({maxTime , nums[i][0]+nums[i][1] , time+nums[i][0]});
        }

        return maxTime;
    }
};