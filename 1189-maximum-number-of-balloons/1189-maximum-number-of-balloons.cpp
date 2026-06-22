class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();

        unordered_map<char,int> mp;

        for(int i = 0 ; i < n ; i++) mp[text[i]]++;

        int mini = min({mp['b'] , mp['a'] , mp['l']/2 , mp['o']/2 , mp['n']});

        return mini;
    }
};