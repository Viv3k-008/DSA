class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        vector<vector<int>> ans;

        sort(intervals.begin() , intervals.end());
        int st = intervals[0][0] , ed = intervals[0][1];

        for(int i = 1 ; i < n ; i++){
            int curSt = intervals[i][0] , curEd = intervals[i][1];
            if(st <= curSt && curSt <= ed){
                ed = max(ed , curEd);
            }
            else {
                ans.push_back({st,ed});
                st = curSt;
                ed = curEd;
            }
        }

        ans.push_back({st,ed});

        return ans;
    }
};