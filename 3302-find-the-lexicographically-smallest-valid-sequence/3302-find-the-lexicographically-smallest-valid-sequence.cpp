class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();


        vector<int> last(m, -1);

        int idx = m-1;
        for(int i = n-1 ; i >= 0 && idx >= 0 ; i--){
            if(word1[i] == word2[idx]){
                last[idx--] = i;
            }
        }
        cout<<endl;

        idx = 0;
        bool changed = false;
        for(int i = 0 ; i < n && idx < m ; i++){
            if(word1[i] == word2[idx]){
                last[idx] = i;
                idx++;
            }
            else if(!changed && ((idx != m-1 && i < last[idx+1]) || (idx == m-1))){
                last[idx] = i;
                idx++;
                changed = true;
            }
        }

        if(idx != m) return vector<int>{};

        return last;
    }
};