class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        int highest = INT_MIN;
        sort(arr.begin(),arr.end());
        
        for(int i : arr){
            highest = max(highest , i);
        }

        int max = 0;
        for(int i = 0 ; i < n ; i++){
            if(max+1 <= arr[i]){
                max++;
            }
            else continue;
        }
        cout<<n;
        return max;
    }
};