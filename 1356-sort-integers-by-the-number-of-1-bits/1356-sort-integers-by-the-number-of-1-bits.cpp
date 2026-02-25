class Solution {
public:
    int form(int n){
        int cnt = 0;
        while(n){
            int rem = n%2;
            if(rem == 1) cnt++;
            n /= 2;
        }

        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> mp;

        for(int i : arr){
            int cnt = form(i);
            mp.push_back({cnt,i});
        }

        sort(mp.begin(),mp.end());
        vector<int> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};