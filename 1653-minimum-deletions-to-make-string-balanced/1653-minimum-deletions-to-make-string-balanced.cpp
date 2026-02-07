class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        if(n == 1) return 0;

        vector<int> pref(n , 0) , suff(n , 0);

        for(int i = 0 ; i < n ; i++){
            pref[i] = (i == 0)? (s[i] == 'b')? 1 : 0 : (s[i] == 'b')? pref[i-1]+1 : pref[i-1];
        }

        for(int i = n-1 ; i >= 0 ; i--){
            suff[i] = (i == n-1)? (s[i] == 'a')? 1 : 0 : (s[i] == 'a')? suff[i+1]+1 : suff[i+1];
        }

        int ans = INT_MAX;
        for(int i = 0 ; i <= n ; i++){
            if(i == 0){
                ans = min(ans , suff[0]);
            }
            else if(i == n){
                ans = min(ans , pref[i-1]);
            }
            else{
                int leftRemoval = pref[i-1];
                int rightRemoval = suff[i];

                ans = min(ans , leftRemoval+rightRemoval);
            }
        }

        return ans;
    }
};