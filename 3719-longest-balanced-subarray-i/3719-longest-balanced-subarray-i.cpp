class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size() , ans = 0;

        for(int i = 0 ; i < n ; i++){
            int lastEve = -1 , lastOdd = -1 , eveCnt = 0 , oddCnt = 0;
            unordered_map<int,bool> m;
            for(int j = i ; j < n ; j++){
                if(nums[j]%2 && m.count(nums[j]) == false){
                    m[nums[j]] = true;
                    oddCnt++;
                }
                else if(nums[j]%2 == 0 && m.count(nums[j]) == false){
                    m[nums[j]] = true;
                    eveCnt++;
                }
                if(oddCnt == eveCnt){
                    ans = max(ans , j-i+1);
                }
            }
        }

        return ans;
    }
};