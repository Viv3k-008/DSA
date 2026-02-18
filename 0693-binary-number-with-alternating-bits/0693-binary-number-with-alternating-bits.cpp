class Solution {
public:
    string bits(int n){
        string s = "";

        while(n){
            s.push_back(n%2+'0');
            n /= 2;
        }

        return s;
    }
    bool hasAlternatingBits(int n) {
        string s = bits(n);

        for(int i = 1 ; i < s.size() ; i++){
            if(!(s[i]-'0') != (s[i-1]-'0')){
                return false;
            }
        }

        return true;
    }
};