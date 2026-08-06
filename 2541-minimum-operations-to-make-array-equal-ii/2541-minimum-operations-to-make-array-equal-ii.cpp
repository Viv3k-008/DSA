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

        long long total = 0, ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums1[i] > nums2[i]){
                if(nums1[i]%k != nums2[i]%k) return -1;
                long long diff = nums1[i]-nums2[i];
                ans += diff/k;
                total += diff;
            }
            else if(nums1[i] < nums2[i]){
                if(nums1[i]%k != nums2[i]%k) return -1;
                long long diff = nums2[i]-nums1[i];
                
                ans += diff/k;
                total -= diff;
            }
            cout<<total<<endl;
        }

        return ans/2;
    }
};