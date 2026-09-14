class Solution {
public:
  
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int i1 = rec2[0], j1 = rec2[1], i2 = rec2[2], j2 = rec2[3];

        if(x2 <= i1 || x1 >= i2 || y2 <= j1 || y1 >= j2) return false;
        return true;
        
    }
};