class Solution {
public:
    typedef long long ll;
    
    // Explicitly chosen primes and large moduli
    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll P1 = 100003;
    const ll P2 = 100019;

    bool check(int mid, vector<int>& nums, int n) {
        vector<int> polve = nums;

        if (mid == 0) return false;

        ll p1_mid = 1, p2_mid = 1;
        for (int i = 0; i < mid; i++) {
            p1_mid = (p1_mid * P1) % MOD1;
            p2_mid = (p2_mid * P2) % MOD2;
        }

        // Using a map of pairs to perfectly separate h1 and h2
        map<pair<ll, ll>, int> mp;
        ll h1 = 0, h2 = 0;

        // Initial window
        for (int i = 0; i < mid; i++) {
            h1 = (h1 * P1 + nums[i]) % MOD1;
            h2 = (h2 * P2 + nums[i]) % MOD2;
        }
        mp[{h1, h2}]++;

       
        for (int i = mid; i < n; i++) {
            h1 = (h1 * P1 + nums[i]) % MOD1;
            h1 = (h1 - (nums[i - mid] * p1_mid) % MOD1 + MOD1) % MOD1;
            h2 = (h2 * P2 + nums[i]) % MOD2;
            h2 = (h2 - (nums[i - mid] * p2_mid) % MOD2 + MOD2) % MOD2;

            mp[{h1, h2}]++;
        }

        for (auto const& [hash_pair, count] : mp) {
            if (count == 1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1 , r = n;

        int ans = -1;
        while(l <= r){
            int mid = l+(r-l)/2;

            if(check(mid , nums , n)){
                r = mid-1;
                ans = mid;
            }
            else l = mid+1;
        }

        return ans;
    }
};