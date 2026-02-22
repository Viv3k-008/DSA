class Solution {
public:
    string bits(int n){
        string s = "";

        while(n){
            int rem = n%2;
            s += rem+'0';
            n /= 2;
        }

        reverse(s.begin(),s.end());

        return s;
    }
    int binaryGap(int n) {
        string s = bits(n);

        int prev = -1;

        int maxi = INT_MIN;

        for(int i = 0 ; i < s.size() ; i++){
            if(prev != -1 && s[i] == '1'){
                maxi = max(maxi , i-prev);
            }

            if(s[i] == '1') prev = i;
        }


        return maxi == INT_MIN? 0 : maxi;
    }
};