class Solution {
public:
    string result = "";
    bool fn(int i, vector<int>& count, string &cur, string &target, bool great){
        if(i == target.size()){
            if(great){
                result = cur;
                return true;
            }
            return false;
        }

        for(int k = 0 ; k < 26; k++){
            if(count[k] == 0) continue;
            if(great == false && (k+'a') < target[i]) continue;

            cur += k+'a';
            count[k]--;

            bool isGreat = (great || (k+'a') > target[i]);
            if(fn(i+1, count, cur, target, isGreat)){
                return true;
            } 

            cur.pop_back();
            count[k]++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for(char c : s) count[c-'a']++;

        string cur = "";

        fn(0, count, cur, target, false);

        return result;
    }
};