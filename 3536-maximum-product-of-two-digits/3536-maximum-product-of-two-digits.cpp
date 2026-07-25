class Solution {
public:
    int maxProduct(int n) {
        int fh = INT_MIN, sh = INT_MIN;

        while(n){
            int rem = n%10;
            n /= 10;

            if(rem > fh){
                sh = fh;
                fh = rem;
            }
            else if(rem > sh){
                sh = rem;
            }
        }

        return (fh*sh);
    }
};