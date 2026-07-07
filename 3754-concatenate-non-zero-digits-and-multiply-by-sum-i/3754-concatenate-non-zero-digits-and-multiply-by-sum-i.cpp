class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0, sum = 0;

        while(n){
            int rem = n%10;
            n /= 10;
            if(rem != 0){
                num *= 10;
                num += rem;
            }
            sum += rem;
        }
        string s = to_string(num);
        reverse(s.begin(),s.end());

        num = stoll(s);

        return  1LL*num*sum;
    }
};