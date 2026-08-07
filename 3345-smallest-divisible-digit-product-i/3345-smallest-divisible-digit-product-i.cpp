class Solution {
public:
    bool check(int n, int t){
        int prod = 1;

        while(n){
            int rem = n%10;
            n /= 10;

            prod *= rem;
        }

        return prod%t == 0;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i <= n+10; i++){
            if(check(i, t)){
                return i;
            }
        }

        return -1;
    }
};