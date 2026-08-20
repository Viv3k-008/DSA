class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();

        queue<pair<int,int>> q;

        int di[4] = {-1 , 1 , 0 , 0};
        int dj[4] = {0 , 0 , -1 , 1};

        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                board[i][0] = '#';
            }
            if(board[i][m-1] == 'O'){
                q.push({i,m-1});
                board[i][m-1] = '#';
            }
        }

        for(int j = 0 ; j < m ; j++){
            if(board[0][j] == 'O'){
                q.push({0,j});
                board[0][j] = '#';
            }
            if(board[n-1][j] == 'O'){
                q.push({n-1,j});
                board[n-1][j] = '#';
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int curi = top.first;
            int curj = top.second;

            for(int k = 0 ; k < 4 ; k++){
                int newi = curi + di[k];
                int newj = curj + dj[k];

                if(newi < 0 || newi >= n || newj < 0 || newj >= m || board[newi][newj] != 'O') continue;

                board[newi][newj] = '#';
                q.push({newi,newj});
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else board[i][j] = 'X';
            }
        }
    }
};