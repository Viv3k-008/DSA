class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
         int n = prices.size();

         vector<int> inc(n , 1);

         for(int i = 1 ; i < n ; i++){
            if((prices[i-1]-prices[i]) == 1){
                inc[i] += inc[i-1];
            }
         }
         
         long long sum = 0;
         for(int i : inc){
            sum += i;
         }

         return sum;
    }
};