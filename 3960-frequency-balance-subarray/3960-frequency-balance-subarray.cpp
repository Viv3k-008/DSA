class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();

        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            unordered_map<int,int> mp;
            map<int,int> freq;
            for(int j = i ; j < n ; j++){
               
                if(mp.count(nums[j]) && freq.count(mp[nums[j]])){
                    freq[mp[nums[j]]]--;
                    if(freq[mp[nums[j]]] == 0){
                        freq.erase(mp[nums[j]]);
                    }
                }
                mp[nums[j]]++;

                freq[mp[nums[j]]]++;

                if(freq.size() == 2){
                    pair<int,int> firstFreq = *freq.begin();
                    pair<int,int> secondFreq = *freq.rbegin();

                    if(firstFreq.first*2 == secondFreq.first){
                        ans = max(ans , j-i+1);
                    }
                }
                else if(mp.size() == 1){
                    ans = max(ans , j-i+1);
                }
            }
        }

        return ans;
    }
};