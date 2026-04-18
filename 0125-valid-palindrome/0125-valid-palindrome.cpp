class Solution {
public:
    char mytolower(char c){
    
        if(c >= 'A' && c <= 'Z'){
           c += ('a'-'A');
        }

        return c;
    }
    bool isAlphaNum(char c) {
        if(c >= 'a' && c <= 'z') return true;
        if(c >= 'A' && c <= 'Z') return true;
        if(c >= '0' && c <= '9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0 , j = s.size()-1;

        while(i < j){
            
            while(i < j && !isAlphaNum(s[i])) i++;
            while(i < j && !isAlphaNum(s[j])) j--;

            if(mytolower(s[i++]) != mytolower(s[j--])){
                return false;
            }
        }


        return true;
    }
};