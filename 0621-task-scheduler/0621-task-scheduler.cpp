class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();

        vector<int> alpha(26, 0);

        for(char i : tasks){
            alpha[i-'A']++;
        }

        sort(alpha.begin(), alpha.end());

        int maxFreq = alpha[25]-1; // gaps in which we will have to fill the chars
        int gaps = maxFreq*n;      // and in that particular gap n spaces(chars) should be their

        for(int i = 24; i >= 0 ; i--){
            int mini = min(alpha[i], maxFreq);
            gaps -= mini;
        }

        return (gaps > 0)? gaps+m : m;
    }
};