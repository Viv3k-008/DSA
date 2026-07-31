class Solution {
public:
    static bool comp(pair<char,int>& a, pair<char,int>& b){
        return a.second > b.second;
    }
    int minimumPushes(string word) {
        int n = word.size();

        int count = 0, alphaCnt = 0, add = 1;

        vector<pair<char,int>> vec;

        unordered_map<char,int> mp;
        for(char c : word) mp[c]++;

        for(auto it : mp) vec.push_back(it);

        sort(vec.begin(),vec.end(),comp);

        for(pair<char,int> it : vec){
            alphaCnt++;

            count += it.second*add;

            if(alphaCnt%8 == 0) add++;
        }
        return count;
    }
};