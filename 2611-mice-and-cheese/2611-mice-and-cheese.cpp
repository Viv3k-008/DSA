class Solution {
public:
    static bool comp(pair<int,pair<int,int>>& a , pair<int,pair<int,int>>& b){
        return a.first > b.first;
    }
   
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();

        vector<pair<int,pair<int,int>>> final(n);

        for(int i = 0 ; i < n ; i++){
            final[i] = {reward1[i]-reward2[i],{reward1[i],reward2[i]}};
        }

        sort(final.begin(), final.end(), comp);

        int ans = 0;

        for(int i = 0 ; i < k ; i++){
            ans += final[i].second.first;
        }
        for(int i = k; i < n ; i++){
            ans += final[i].second.second;
        }


        return ans;
    }
};