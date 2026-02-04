class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
          long long ans = -1e18;

          long long prev = nums[0];
          int n = nums.size();

          long long a = -1e17;
          long long b = -1e17;
          long long c = -1e17;
          for(int i = 1 ; i < n ; i++){
            long long new_a = -1e17;
            long long new_b = -1e17;
            long long new_c = -1e17;

            long long cur = nums[i];
            if(cur > prev){
                new_a = max(a , prev) + cur;
                new_c = max(b , c) + cur;
            }
            else if(cur < prev){
                new_b = max(b , a) + cur;
            }

            a = new_a;
            b = new_b;
            c = new_c;

            ans = max(ans , c);
            prev = cur;
          }

          return ans;
    }
};