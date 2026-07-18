class Solution {
public:
    int findGcd(int a, int b){
        if(b == 0){
            return a;
        }

        return findGcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN, mini = INT_MAX;

        for(int i : nums){
            maxi = max(i, maxi);
            mini = min(mini, i);
        }

        return findGcd(maxi, mini);
    }
};