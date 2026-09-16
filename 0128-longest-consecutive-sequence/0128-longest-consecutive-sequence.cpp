class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> left, right, vis;

        for(int i = n-1; i >= 0 ; i--){
            right[nums[i]]++;
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            right[nums[i]]--;
            if(right[nums[i]] == 0){
                right.erase(nums[i]);
            }

            if(left.count(nums[i]+1)){
                ans = max(ans, left[nums[i]+1]+1);
                left[nums[i]] = left[nums[i]+1]+1;
            }

            int cnt = 1, temp = nums[i]+1;
            if(vis.count(temp)) continue;
            while(right.count(temp)){
                vis[temp]++;
                cnt++;
                temp++;
            }
            if(left.count(temp)) cnt += left[temp];
            if(cnt != 0) left[nums[i]] = cnt;
            ans = max(ans, cnt);
        }

        return ans;
    }
};