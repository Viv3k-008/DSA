class Solution {
public:
    
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        string ans = "";
        for(int i = 0 ; i < n ; i++){
            int ones = 0;
            string temp = "";
            for(int j = i ; j < n ; j++){
                if(s[j] == '1') ones++;

                string temp = s.substr(i, j-i+1);
                if(ones == k){
                    if(ans == "" || temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans)){
                        ans = temp;
                    }
                }
            }
        }


        return  ans;
    }
};