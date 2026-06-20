class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        
        r.push_back({1,0});

        sort(r.begin(),r.end());

        // if no restriction for nth building so add n,n-1 as height
        if(r.back()[0] != n){
            r.push_back({n,n-1});
        }

        int m = r.size();

        for(int i = 1 ; i < m ; i++){
            int dist = r[i][0] - r[i-1][0];
            r[i][1] = min(r[i][1] , r[i-1][1]+dist);
        }
        for(int i = m-2 ; i >= 0 ; i--){
            int dist = r[i+1][0] - r[i][0];
            r[i][1] = min(r[i][1] , r[i+1][1]+dist);
        }

        int ans = 0;
        for(int i = 1 ; i < m ; i++){
            int x1 = r[i-1][0] , h1 = r[i-1][1];
            int x2 = r[i][0] , h2 = r[i][1];

            int d = x2-x1;
            ans = max(ans , (h1+h2+d)/2);
        }

        return ans;
    }
};