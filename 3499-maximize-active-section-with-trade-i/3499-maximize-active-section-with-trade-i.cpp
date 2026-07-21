class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int l = 0, r = n-1;
        while(l < n && s[l] == '1') l++;
        while(r >= 0 && s[r] == '1') r--;

        vector<int> prefOne(n);
        for(int i = 0 ; i < n ; i++){
            prefOne[i] = (i == 0)? s[i]-'0' : s[i]-'0'+prefOne[i-1];
        }

        vector<int> suffZero(n), prefZero(n);
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1'){
                prefZero[i] = 0;
                cnt = 0;
            }
            else {
                cnt++;
                prefZero[i] = cnt;
            }
        }
        cnt = 0;

        for(int i = n-1; i >= 0 ; i--){
            if(s[i] == '1'){
                suffZero[i] = 0;
                cnt = 0;
            }
            else {
                cnt++;
                suffZero[i] = cnt;
            }
        }

        int ans = 0;

        int lidx = -1, ridx = -1;
        for(int i = l; i <= r ; i++){
            if(s[i] == '1'){
                lidx = i;
                ridx = i;
                while(ridx <= r && s[ridx] == '1'){
                    ridx++;
                }

                ans = max(ans, ridx-lidx + prefZero[lidx-1]+suffZero[ridx] + prefOne[lidx-1]+prefOne[n-1]-prefOne[ridx-1]);

                i = ridx-1;
            }
        }

        if(ans == 0){
            return prefOne[n-1];
        }

        return ans;
    }
};