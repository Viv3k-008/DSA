class Solution {
public:

    int minimumPushes(string word) {
        int n = word.size();

        int count = 0, alphaCnt = 0, add = 1;

        vector<int> freq(1e5+1,0);

        vector<int> alpha(26,0);
        for(char c : word) alpha[c-'a']++;

        for(int c : alpha) freq[c]++;

        vector<int> freqWord;


        for(int i = 1e5 ; i > 0 ; i--){
            while(freq[i]--){
                alphaCnt++;
                count += i*add;
                if(alphaCnt%8 == 0) add++;
            }
        }
        return count;
    }
};