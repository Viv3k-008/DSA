class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        vector<int> f(n), b(n);

        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            if((sum + arr[i]) >= 0){
                sum += arr[i];
                f[i] = sum;
            }
            else {
                sum = 0;
                f[i] = arr[i];
            }
        }

        sum = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if((sum+arr[i]) >= 0){
                sum += arr[i];
                b[i] = sum;
            }
            else{
                b[i] = arr[i];
                sum = 0;
            }
        }

        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                ans = max({ans , b[i], arr[i]});
            }
            else if(i == n-1){
                ans = max({ans , f[i], arr[i]});
            }
            else ans = max({ans, f[i-1]+b[i+1], f[i], b[i], arr[i]});
        }

        return ans;
    }
};