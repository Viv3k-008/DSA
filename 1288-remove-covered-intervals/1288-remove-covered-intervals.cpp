class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& interval) {
        int n = interval.size();

        sort(interval.begin(),interval.end(),comp);
        int ans = 0;
        int st = -1, ed = -1;

        for(int i = 0 ; i < n ; i++){
            int curSt = interval[i][0];
            int curEd = interval[i][1];

            if(st == -1 && ed == -1){
                st = curSt;
                ed = curEd;
                ans++;
                continue;
            }
            else if(curSt >= st && curEd <= ed){
                continue;
            }
            else {
                ans++;
                st = curSt;
                ed = curEd;
            }
        }

        return ans;
    }
};