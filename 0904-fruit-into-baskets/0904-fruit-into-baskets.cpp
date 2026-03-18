class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
       
        unordered_map<int,int> mp;
        int left = 0 , maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            mp[fruits[i]]++;
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[left]]--;
                    if(mp[fruits[left]] == 0){
                        mp.erase(fruits[left]);
                    }
                    left++;
                }
            }
            maxi = max(i-left+1 , maxi);
        }

        return maxi;
    }
};