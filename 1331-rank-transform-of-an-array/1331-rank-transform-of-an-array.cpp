class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        for(int i : arr){
            mp[i] = 0;
        }
        int cnt = 0;
        for(auto &it : mp) it.second = ++cnt;

        vector<int> ans;
        for(int i : arr) ans.push_back(mp[i]);

        return ans; 
    }
};