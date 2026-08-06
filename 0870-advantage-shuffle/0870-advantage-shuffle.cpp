class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        map<int,int> mp;
        for(int i : nums1) mp[i]++;
        vector<int> ans(n, -1);

        for(int i = 0 ; i < n ; i++){
            auto it = mp.upper_bound(nums2[i]);

            if(it != mp.end()){
                ans[i] = it->first;
                
                it->second--;
                if(it->second == 0){
                    mp.erase(it);
                }
            }
        }

        vector<int> temp;
        for(auto it : mp){
            while(it.second--) temp.push_back(it.first);
        }

        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            if(ans[i] == -1){
                ans[i] = temp[idx++];
            }
        }

        return ans;
    }
};