class Solution {
public:
    long long findGcd(int a, int b){
        if(b == 0){
            return a;
        }

        return findGcd(b, a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> gcd(n);

        long long maxi = LLONG_MIN;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi, 1LL*nums[i]);

            gcd[i] = findGcd(maxi,nums[i]);
        }

        sort(gcd.begin(),gcd.end());

        long long ans = 0;

        int l = 0, r = n-1;
        while(l < r){
            ans += findGcd(gcd[l],gcd[r]);
            l++ , r--;
        }

        return ans;
    }
};