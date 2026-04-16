class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int tMax = INT_MIN , idx = -1 , lMax = height[0] , rMax = height[n-1] , water = 0;

        for(int i = 0 ; i < n ; i++){
            if(height[i] > tMax){
                tMax = height[i];
                idx = i;
            }
        }


        // left Part
        for(int i = 1 ; i < idx ; i++){
            if(lMax > height[i]){
                water += lMax - height[i];
            }
            else lMax = height[i];
        }

        // right Part
        for(int i = n-2 ; i > idx ; i--){
            if(rMax > height[i]){
                water += rMax - height[i];
            }
            else rMax = height[i];
        }

        return water;
    }
};