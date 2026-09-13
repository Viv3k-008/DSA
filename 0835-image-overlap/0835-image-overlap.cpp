class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        map<pair<int,int>,int> mp;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(img1[i][j] != 1) continue;
                for(int k = 0 ; k < n ; k++){
                    for(int l = 0 ; l < n ; l++){
                        if(img2[k][l] != 1) continue;

                        int xDis = k-i;
                        int yDis = l-j;

                        mp[{xDis,yDis}]++;
                        ans = max(ans, mp[{xDis,yDis}]);
                    }
                }
            }
        }

        return ans;
    }
};