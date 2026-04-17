class Solution {
public:
    bool fn(int i , int j , string& s , string& p){
        if(j == p.size()){
            return i == s.size();
        }


        bool take = false , notTake = false , firstCharMatch = false;

        if(i < s.size() && (s[i] == p[j] || p[j] == '.')){
            firstCharMatch = true;
        }

        if(j+1 < p.size() && p[j+1] == '*'){
            take = firstCharMatch && fn(i+1 , j , s , p);
            notTake = fn(i , j+2 , s , p);

            return take || notTake;
        }

        return firstCharMatch && fn(i+1 , j+1 , s , p);
    }
    bool isMatch(string s, string p) {
        
        return fn(0 , 0 , s , p);
    }
};