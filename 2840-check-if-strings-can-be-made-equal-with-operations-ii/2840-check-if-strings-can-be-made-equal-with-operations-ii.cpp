class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        map<char,int> s1Even , s1Odd , s2Even , s2Odd;

        for(int i = 0 ; i < n ; i++){
            if(i%2){
                s1Odd[s1[i]]++;
                s2Odd[s2[i]]++;
            }
            else {
                s1Even[s1[i]]++;
                s2Even[s2[i]]++;
            }
        }

        return s1Even == s2Even && s1Odd == s2Odd;
    }
};