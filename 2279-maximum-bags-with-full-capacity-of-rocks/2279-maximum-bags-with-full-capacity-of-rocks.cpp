class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();

        vector<int> left;
        for(int i = 0 ; i < n ; i++){
            left.push_back(capacity[i]-rocks[i]);
        }

        sort(left.begin(), left.end());

        int extra = additionalRocks;
        int i = 0, ans = 0;
        while(i < left.size() && extra >= left[i]){
            ans++;
            extra -= left[i++];
        }

        return ans;
    }
};