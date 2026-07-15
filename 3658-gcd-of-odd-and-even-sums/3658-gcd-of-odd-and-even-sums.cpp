class Solution {
public:
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }

        return gcd(b, a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int evenSum = n*(n+1);
        int oddSum = 2*n*(2*n+1)/2 - n*(n+1);  // after simplifying it will be n*n

        return gcd(evenSum, oddSum);
    }
};