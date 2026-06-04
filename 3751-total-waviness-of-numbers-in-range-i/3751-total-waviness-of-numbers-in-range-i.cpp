class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for(int i = num1 ; i <= num2 ; i++){
            string s = to_string(i);

            int n = s.size();
            if(n < 3) continue;
            for(int k = 0 ; k < n ; k++){
                if(k == 0 || k == n-1) continue;
                if((s[k]-'0' > s[k-1]-'0') && (s[k]-'0' > s[k+1]-'0')){
                    total++;
                }
                else if((s[k]-'0' < s[k-1]-'0') && (s[k]-'0' < s[k+1]-'0')){
                    total++;
                }
            }
        }

        return total;
    }
};