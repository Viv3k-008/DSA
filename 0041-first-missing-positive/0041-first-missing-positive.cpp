class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;

        int num = 1;

        while(num){
            if(!mp.count(num)){
                return num;
            }
            num++;
        }

        return -1;
    }
};