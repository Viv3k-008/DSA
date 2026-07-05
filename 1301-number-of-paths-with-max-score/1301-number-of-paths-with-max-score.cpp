class Solution {
public:
    int MOD = 1e9+7;
    int dx[3] = {-1, 0, -1};
    int dj[3] = {0, -1, -1};
    pair<int,int> maxSum(int i, int j, vector<string>& board, vector<vector<pair<int,int>>>& dp){
        if(i == 0 && j == 0){
            return {0,1};
        }
        if(i < 0 || j < 0 || board[i][j] == 'X') return {-1e9,0};

        if(dp[i][j].first != -1) return dp[i][j];

        int maxi = INT_MIN, cnt = 0;
        for(int k = 0 ; k < 3 ; k++){
            int newi = i+dx[k];
            int newj = j+dj[k];

            pair<int,int> cur = maxSum(newi, newj, board, dp);
            if(maxi < cur.first){
                maxi = cur.first;
                cnt = cur.second;
            }
            else if(maxi == cur.first){
                cnt = (cur.second+cnt)%MOD;
            }
        }
        if(maxi == -1e9) return dp[i][j] = {-1e9,0};


        return dp[i][j] = {maxi+(board[i][j]-'0'),cnt};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        board[0][0] = '0';
        board[n-1][n-1] = '0';

        vector<vector<pair<int,int>>> dp(n , vector<pair<int,int>>(n, {-1,0}));
        auto maxi = maxSum(n-1, n-1, board, dp);

        return {maxi.first==-1e9? 0 : maxi.first,maxi.second};
    }
};