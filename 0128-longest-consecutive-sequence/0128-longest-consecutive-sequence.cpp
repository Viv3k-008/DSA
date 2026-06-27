class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st(nums.begin(),nums.end());

        int ans = 0;
        for(int i : st){

            int num = i, len = 1;
            if(!st.count(num-1)){

                while(num != 1e9 && st.count(num+1)){
                    num++;
                    len++;
                }
            }

            ans = max(ans , len);
        }

        return ans;
    }
};