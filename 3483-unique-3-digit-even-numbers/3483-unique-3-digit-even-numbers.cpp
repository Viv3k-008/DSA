class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        int ans = 0;
        unordered_map<string,int> mp;
        for(int i = 0 ; i < digits.size(); i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                for(int k = 0 ; k < n ; k++){
                    if(k == i || k == j) continue;

                    if(digits[i]%2 == 0 && digits[k] != 0){
                        string s = "";
                        s += digits[i]+'0';
                        s += digits[j]+'0';
                        s += digits[k]+'0';

                        if(mp.count(s)) continue;
                        else {
                            ans++;
                            mp[s]++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};