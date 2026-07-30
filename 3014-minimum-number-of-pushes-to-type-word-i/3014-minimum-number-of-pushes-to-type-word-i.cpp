class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int count = 0, add = 1;
        
        for(int i = 0 ; i < n ; i++){
            count += add;
            if((i+1)%8 == 0) add++;
        }

        return count;
    }
};