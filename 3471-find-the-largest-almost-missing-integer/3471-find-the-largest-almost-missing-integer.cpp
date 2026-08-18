class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> digit(51,0), temp(51,0);
        for(int i = 0 ; i < k ; i ++){
            temp[nums[i]]++;
        }
        for(int i = 0; i < 51; i++){
            if(temp[i] > 0){
                digit[i]++;
            }
        }

        int l = 0;
        for(int i = k ; i < n ; i++){
            l++;

            temp.assign(51, 0);
            for(int j = l; j <= i ; j++){
               temp[nums[j]]++;
            }
            for(int j = 0 ; j < 51; j++){
                if(temp[j] > 0){
                    digit[j]++;
                }
            }
        }

        int ans = -1;
        for(int i = 0 ; i < 51; i++){
            if(digit[i] == 1){
                ans = max(i, ans);
            }
        }

        return ans;
    }
};