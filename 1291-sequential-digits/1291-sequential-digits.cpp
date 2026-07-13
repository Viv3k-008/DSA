class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string s = to_string(low);
        string e = to_string(high);

        int n = s.size(), m = e.size();
        bool done = false;

        for(int i = n ; i <= m ; i++){
            int ed = (10-i);
            for(int c = 1 ; c <= ed ; c++){
                int cur = 0;
                int d = c;
                for(int len = 0 ; len < i ; len++){
                    cur *= 10;
                    cur += d;
                    d += 1;
                }

                if(cur >= low && cur <= high) ans.push_back(cur);
                if(cur > high){
                    done = true;
                    break;
                }
            }
            if(done) break;
        }


        return ans;
    }
};