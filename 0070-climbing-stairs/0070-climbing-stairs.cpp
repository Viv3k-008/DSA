class Solution {
public:
    int climbStairs(int n) {
        
        int prev = 1 , secPrev = 0;

        for(int i = n-1 ; i >= 0 ; i--){
            int cur = prev + secPrev;
            secPrev = prev;
            prev = cur;
        }

        return prev;
    }
};