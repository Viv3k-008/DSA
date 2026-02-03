class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       int u1 = edges[0][0] , v1 = edges[0][1];
       int u2 = edges[1][0] , v2 = edges[1][1];

       if(u1 == u2 || u1 == v2) return u1;
       if(v1 == u2 || v1 == v2) return v1;

       return -1;
    }
};