class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(),arr.end());

        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            if(maxi+1 <= arr[i]){
                maxi++;
            }
        }

        return maxi;
    }
};