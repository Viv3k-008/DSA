class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int idx = 0, count = 0, add = 1;;
        while(idx < n){
            for(int i = 0 ; i < 8 ; i++){
                count += add;
                idx++;
                if(idx == n) break;
            }
            if(idx == n) break;
            add++;
        }

        return count;
    }
};