class Solution {
public:
    vector<vector<string>> ans;
    bool check(int i , int j , vector<string>& board , int n){

        int newi = i , newj = j;

        // diagonally left up
        while(newi >= 0 && newj >= 0){
            if(board[newi][newj] == 'Q'){
                return false;
            }
            newi-- , newj--;
        }

        // horizontally left
        newi = i , newj = j;
        while(newj >= 0){
           if(board[newi][newj] == 'Q'){
                return false;
            }
            newj--;
        }

        // diagonally left downwards
        newi = i , newj = j;
        while(newi < n && newj >= 0){
            if(board[newi][newj] == 'Q'){
                return false;
            }
            newi++ , newj--;
        }

        return true;

    }
    void fn(int j , vector<string>& board , int n){
        if(j == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0 ; i < n ; i++){
            if(check(i , j , board , n)){
                board[i][j] = 'Q';
                fn(j+1 , board , n);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n , string(n , '.'));

        fn(0 , board , n);

        return ans;
    }
};