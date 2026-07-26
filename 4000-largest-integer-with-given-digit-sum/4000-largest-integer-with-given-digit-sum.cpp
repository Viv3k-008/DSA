class Solution {
public:
    int largestInteger(int n, int s) {
        int t = s;

        int num = 0;

        if(s > n*9) return -1;

        for(int i = 0 ; i < n ; i++){
            if(t == 0){
                num *= 10;
            }
            for(int j = 9 ; j > 0 ; j--){
                 if(t >= j){
                    num *= 10;
                    num += j;
                    t -= j;
                    break;
                 }
            }
        }
        

        return num;
    }
};