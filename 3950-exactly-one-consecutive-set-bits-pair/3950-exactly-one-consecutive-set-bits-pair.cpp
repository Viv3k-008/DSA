class Solution {
public:
    string fn(int n){
        string s = "";

        while(n){
            s +=( n%2) + '0';
            n /= 2;
        }

        reverse(s.begin() , s.end());

        return s;
    }
    bool consecutiveSetBits(int n) {

        if(n == 0) return false;

        string s = fn(n);

        int cnt = 0;
        for(int i = 0 ; i < s.size()-1 ; i++){
           
            if(s[i] == '1' && s[i+1] == '1'){
                cnt++;
            }
                   
        }

        return cnt == 1;
    }
};