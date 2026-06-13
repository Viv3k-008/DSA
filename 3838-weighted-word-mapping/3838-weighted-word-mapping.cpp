class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();

        unordered_map<int , char> mp;
        int temp = 25;

        for(char c = 'a' ; c <= 'z' ; c++){
            mp[temp--] = c;
        }

        string ans = "";
        for(int i = 0 ; i < n ; i++){
            string s = words[i];

            int sum = 0;
            for(int j = 0 ; j < s.size() ; j++){
                sum += weights[s[j]-'a'];
            }

            ans += mp[sum%26];
        }


        return ans;
    }
};