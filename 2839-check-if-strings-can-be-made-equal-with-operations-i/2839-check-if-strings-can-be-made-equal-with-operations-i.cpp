class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string s3 = s1;

        for(int i =0 ; i < 2 ; i++){
            if(s3[i] != s2[i]){
                swap(s3[i],s3[i+2]);
            }
        }

        return s3 == s2;
    }
};