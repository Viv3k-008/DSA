class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();

        int maxVal = INT_MIN;
        for(int i : nums) maxVal = max(maxVal, i);

        vector<int> divisorCnt(maxVal+1, 0);

        for(int i = 0 ; i < n ; i++){
            int num = nums[i];

            for(int j = 1 ; j*j <= num ; j++){
                if(num%j == 0){
                    divisorCnt[j]++;
                    if(num/j != j){
                        divisorCnt[num/j]++;
                    }
                }
            }
        }

        vector<long long> pairCnt(maxVal+1, 0);
        for(int i = maxVal ; i >= 1 ; i--){
            long long cnt = divisorCnt[i];

            // nc2
            pairCnt[i] = cnt*(cnt-1)/2;

            // we will have to remove the count , if its higher multiple has any count
            for(int k = 2*i ; k <= maxVal ; k += i){
                pairCnt[i] -= pairCnt[k];
            }
        }

        vector<long long> prefixCntGcd(maxVal+1, 0);
        for(int i = 1 ; i <= maxVal ; i++){
            prefixCntGcd[i] = prefixCntGcd[i-1]+pairCnt[i];
        }

        vector<int> result;

        for(long long idx : queries){
            int l = 0 , r = maxVal;
            int ans = 1;

            while(l <= r){
                int mid = l+(r-l)/2;

                if(prefixCntGcd[mid] > idx){
                    ans = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }

            result.push_back(ans);
        }

        return result;
    }
};