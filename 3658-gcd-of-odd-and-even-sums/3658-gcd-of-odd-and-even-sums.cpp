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
        int oddSum = n*2*(n*2+1)/2 - n*(n+1);

        return gcd(evenSum, oddSum);
    }
};