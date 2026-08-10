class Solution {
public:
    vector<int> dp;
    int fn(int i, int n, vector<int>& square){
        if(i > n) return 0;
    
        if(dp[i] != -1) return dp[i];

        int op = -1e9;
        for(int k = square.size()-1 ; k >= 0 ; k--){
            if((i+square[k]) <= n){
                op = max(op, square[k]-fn(i+square[k], n, square));
            }
        }

        return dp[i] = op;
    }
    bool winnerSquareGame(int n) {
        int s = 1;
        vector<int> square;
        for(int i = 1; i <= 1000 ; i++){
            s = i*i;
            if(s > 1e5) break;
            square.push_back(s);
        }
        dp.resize(n+1, -1);
        return (fn(0, n, square) > 0)? true : false;
    }
};