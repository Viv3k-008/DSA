class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
       
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int cnt = 0;
        int ed = -1e9;

        sort(intervals.begin(), intervals.end(), comp);

        for(int i = 0 ; i < n ; i++){
            if(ed <= intervals[i][0]){
                cnt++;
                ed = intervals[i][1];
            }
        }

        return n-cnt;
    }
};