class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        for(int i : nums1){
            sum1 += i;
        }
        for(int i : nums2){
            sum2 += i;
        }
        if(sum1 == sum2) return 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());


        int diff = abs(sum1-sum2);
        if(sum1 > sum2) swap(nums1, nums2);
        int n = nums1.size(), m = nums2.size();


        int i = 0, j = m-1, ans = 0;

        while(i < n || j >= 0){
            int dec = (j >= 0)? nums2[j]-1: -1;
            int inc = (i < n)? 6-nums1[i]: -1;

            if(inc >= dec){
                diff -= inc;
                ans++;
                i++;
            }
            else {
                diff -= dec;
                ans++;
                j--;
            }

            if(diff <= 0) break;
        }

        return (diff <= 0)? ans : -1;

    }
};