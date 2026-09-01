public class Solution {
    public bool IsAnagram(string s, string t) {
        if(s.Length != t.Length) return false;
        
        int[] cnt = new int[26];

        for(int i = 0;  i < s.Length; i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }

        foreach(int freq in cnt){
            if(freq != 0){
                return false;
            }
        }

        return true;
    }
}