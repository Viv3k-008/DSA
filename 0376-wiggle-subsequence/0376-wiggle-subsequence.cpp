// DP arrpoach
// int wiggleMaxLength(vector<int>& nums) {
//     int n = nums.size();

//     vector<int> dp1(n, 1), dp2(n, 1);

//     // dp1 -> stores the max length of sequence when number is taking next element as greater
//     // dp2 -> stores the max length of sequence when number is taking next element as smaller

//     int ans = INT_MIN;

//     for(int i = n-1; i >= 0; i--){
//         // greater
//         for(int k = i+1; k < n ; k++){
//             if(nums[i] < nums[k]){
//                 dp1[i] = max(dp1[i], 1+dp2[k]);
//             }
//         }

//         // lower
//         for(int k = i+1; k < n ; k++){
//             if(nums[i] > nums[k]){
//                 dp2[i] = max(dp2[i], 1+dp1[k]);
//             }
//         }

//         ans = max({ans, dp1[i], dp2[i]});
//     }

//     return ans;
// }

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        int valley = 1, peak = 1;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i-1]) peak = valley+1;
            else if(nums[i] < nums[i-1]) valley = peak+1;
        }

        return max(peak,valley);
    }
};