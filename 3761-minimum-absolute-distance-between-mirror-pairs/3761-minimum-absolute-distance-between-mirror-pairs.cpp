class Solution {
public:
    long long rev(long long n){
        long long temp = 0;

        while(n%10 == 0){
            n /= 10;
        }
        while(n){
            int rem = n%10;
            n /= 10;
            temp = temp*10 + rem;
        }

        return temp;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int n = nums.size();

        int ans = INT_MAX;
        for(int i = n-1 ; i >= 0 ; i--){
            long long reve = rev((long long) nums[i]);

            if(mp.count(reve)){
                ans = min(ans , abs(mp[reve] - i));
            }
             mp[nums[i]] = i;
        }

        return (ans > n)? -1 : ans;
    }
};