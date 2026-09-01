public class Solution {
    public bool IsAnagram(string s, string t) {
        if(s.Length != t.Length) return false;
        Dictionary<char,int> mp = new Dictionary<char,int>();

        foreach(char c in s){
            if(mp.ContainsKey(c)){
                mp[c]++;
            }
            else mp[c] = 1;
        }

        foreach(char c in t){
            if(!mp.ContainsKey(c)){
                return false;
            }

            mp[c]--;
            if(mp[c] < 0){
                return false;
            }
        }

        return true;
    }
}