class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> left(n , vector<int>(2 , 1)) , right(n , vector<int>(2 , 1));

        for(int i = 1 ; i < n ; i++){
            if(nums[i-1] < nums[i]){
                left[i][1] += left[i-1][0];
            }
            else if(nums[i-1] > nums[i]){
                left[i][0] += left[i-1][1];
            }
            else continue;
        }

        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i] > nums[i+1]){
                right[i][1] += right[i+1][0];
            }
            else if(nums[i] < nums[i+1]){
                right[i][0] += right[i+1][1];
            }
            else continue;
        }

        int ans = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                ans = max({ans , right[i][0] , right[i][1]});
            }
            else if(i == n-1){
                ans = max({ans , left[i][0] , left[i][1]});
            }
            else{
                // can be anythingh means without removing
                ans = max({ans , left[i][0] , left[i][1] , right[i][0] , right[i][1]});

                // now we can remove one
                // for <
                if(nums[i-1] < nums[i+1]){
                    ans = max(ans , left[i-1][0]+right[i+1][1]);
                }
                else if(nums[i-1] > nums[i+1]){
                    ans = max(ans , left[i-1][1]+right[i+1][0]);
                }
                else continue;
            }
        }

        return ans;
    }
};