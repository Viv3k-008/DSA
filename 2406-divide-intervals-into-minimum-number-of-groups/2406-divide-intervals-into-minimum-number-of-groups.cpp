class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = 1e6+2;

        vector<int> temp(n, 0);

        for(int i = 0 ; i < intervals.size(); i++){
            int left = intervals[i][0];
            int right = intervals[i][1];

            temp[left]++;
            temp[right+1]--;
        }
        int ans = 0;
        for(int i = 1; i < n ; i++) temp[i] += temp[i-1], ans = max(ans, temp[i]);

        return ans;
    }
};