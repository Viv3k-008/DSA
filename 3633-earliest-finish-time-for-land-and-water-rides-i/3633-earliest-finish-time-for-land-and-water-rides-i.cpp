class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size() , m = waterStartTime.size();

        vector<int> land(n) , water(m);

        for(int i = 0 ; i < n ; i++){
            land[i] = (landStartTime[i]+landDuration[i]);
        }
        for(int i = 0 ; i < m ; i++){
            water[i] = (waterStartTime[i]+waterDuration[i]);
        }

        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(land[i] >= waterStartTime[j]){
                    mini = min(mini , land[i]+waterDuration[j]);
                }
                else mini = min(mini , water[j]);
            }
        }

        for(int j = 0 ; j < m ; j++){
            for(int i = 0 ; i < n ; i++){
                if(water[j] >= landStartTime[i]){
                    mini = min(mini , water[j]+landDuration[i]);
                }
                else mini = min(mini , land[i]);
            }
        }

        return mini;
    }
};