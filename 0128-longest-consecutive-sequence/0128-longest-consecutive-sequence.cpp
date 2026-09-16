class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(int i : nums){
            st.insert(i);
        }

        int ans = 0;
        for(int i : st){
            int num = i;
            if(!st.count(num-1)){
                int cnt = 1;
                while(st.count(num+1)){
                    cnt++;
                    num++;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};