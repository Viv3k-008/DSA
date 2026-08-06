class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        long long total1 = 0, total2 = 0;
        for(int i : nums1) total1 += i;
        for(int i : nums2) total2 += i;

        if(total1 != total2) return -1;

        if(k == 0){
            for(int i = 0 ; i < n ; i++){
                if(nums1[i] != nums2[i]){
                    return -1;
                }
            }
            return 0;
        }

        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            long long diff = nums1[i]-nums2[i];
            
            if(diff == 0) continue;
            else if(nums1[i]%k != nums2[i]%k) return -1;

            ans += abs(diff)/k;
         
        }

        return ans/2;
    }
};