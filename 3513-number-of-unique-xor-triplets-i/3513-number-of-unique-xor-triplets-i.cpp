class Solution {
public:
    
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        for(int i : nums) maxi = max(maxi, i);

        int len = (int)log2(maxi)+1;

        if(maxi <= 2){
            return maxi;
        }
        else return (1<<len);

    }
};