class Solution {
public:
    bool check(string& numsi , string& numsj){
        if(numsi.size() != numsj.size()+1) return false;
        int i = 0 , j = 0;
        while(i < numsi.size()){
            if(numsi[i] == numsj[j]) i++ , j++;
            else i++;
        }
        if(j == numsj.size()) return true;
        else return false;
        
    }
    bool static compareLength(string& a , string& b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int ans = INT_MIN;
        sort(words.begin(),words.end() , compareLength);
        vector<int> dp(n , 1);
        for(int i = 0 ; i < n ; i++){
            for(int j = i-1 ; j >= 0 ; j--){
                if(check(words[i] , words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
            if(dp[i] > ans){
               ans = dp[i];
            }
        }

        return ans;
    }
};