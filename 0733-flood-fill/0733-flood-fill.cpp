class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size() , m = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldColor = image[sr][sc];
        image[sr][sc] = color;

        int di[4] = {-1 , 1 , 0 , 0};
        int dj[4] = {0 , 0 , -1 , 1};

        vector<vector<bool>> vis(n , vector<bool>(m , false));
        vis[sr][sc] = true;
 
        while(!q.empty()){
            auto top = q.front();

            int i = top.first;
            int j = top.second;
            q.pop();

            for(int k = 0 ; k < 4 ; k++){
                int newi = i+di[k];
                int newj = j+dj[k];

                if(newi < 0 || newj < 0 || newi >= n || newj >= m || image[newi][newj] != oldColor || vis[newi][newj]){
                    continue;
                }

                image[newi][newj] = color;
                vis[newi][newj] = true;
                q.push({newi,newj});
            }
        }


        return image;
    }
};