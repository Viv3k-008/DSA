class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;

        int n = s.length();

        int[] arr1 = new int[26];
        int[] arr2 = new int[26];
        Arrays.fill(arr1,0);
        Arrays.fill(arr2,0);

        for(int i =  0 ; i < n ; i++){
            arr1[s.charAt(i) - 'a']++;
            arr2[t.charAt(i) - 'a']++;
        }

        for(int i = 0 ; i<26; i ++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }

        return true;
    }
}