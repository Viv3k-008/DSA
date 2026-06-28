class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(),arr.end());

        int max = 0;
        for(int i = 0 ; i < n ; i++){
            if(max+1 <= arr[i]){
                max++;
            }
        }

        return max;
    }
};