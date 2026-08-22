class Solution {
public:
    bool checkDivisibility(int N) {
        long long sum = 0, mul = 1;

        int n = N;

        while(n){
            int rem = n%10;
            n /= 10;

            sum += rem;
            mul *= 1LL*rem;
        }
        
        return N%(sum+mul) == 0;
    }
};