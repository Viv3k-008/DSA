class Solution {
public:
    int missingMultiple(vector<int>& nums, int K) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }

        int k = K;
        while(true){
            if(!mp.count(k)){
                return k;
            }
            k += K;
        }

        return -1;
    }
};