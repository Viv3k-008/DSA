class Solution {
public:
    bool nums[2048] = {false};
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<bool>> mp(n, vector<bool>(2048,false));

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                int xr = nums[i];
                xr ^= nums[j];
                mp[i][xr] = true;
            }
        }

        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = 0 ; j < 2048 ; j++){
                if(mp[i+1][j] == true){
                    mp[i][j] = true;
                }
            }
        }
        vector<bool> check(2048,false);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 2048 ; j++){
                if(mp[i][j] == true){
                    int xr = nums[i];
                    xr ^= j;
                    check[xr] = true;
                }
            }
        }

        int cnt = 0;
        for(int i = 0 ; i < 2048 ; i++){
            if(check[i] == true) cnt++;
        }

        for(int i = 0 ; i < n ; i++){
            if(check[nums[i]] == false){
                cnt++;
            }
        }

        return cnt;
    }
};