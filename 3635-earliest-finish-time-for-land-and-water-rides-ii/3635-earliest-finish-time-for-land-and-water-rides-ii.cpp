class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size() , m = waterStartTime.size();

        vector<int> land(n) , water(m);

        // finding total time for both land and water tour
        for(int i = 0 ; i < n ; i++){
            land[i] = (landStartTime[i]+landDuration[i]);
        }
        for(int i = 0 ; i < m ; i++){
            water[i] = (waterStartTime[i]+waterDuration[i]);
        }

        // now checking all posibilities

        int ans = INT_MAX;

        // 1-> land tour first
        int minLand = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            minLand = min(minLand , land[i]);
        }

        for(int i = 0 ; i < m ; i++){
            if(minLand >= waterStartTime[i]){
                ans = min(ans , minLand+waterDuration[i]);
            }
            else ans = min(ans , water[i]);
        }

        // 2-> water tour first
        int minWater = INT_MAX;
        for(int i = 0 ; i < m ; i++){
            minWater = min(minWater , water[i]);
        }

        for(int i = 0 ; i < n ; i++){
            if(minWater >= landStartTime[i]){
                ans = min(ans , minWater+landDuration[i]);
            }
            else ans = min(ans , land[i]);
        }

        return ans;
    }
};