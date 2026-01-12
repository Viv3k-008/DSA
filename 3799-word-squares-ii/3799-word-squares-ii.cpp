class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> ans;

        for(int top = 0 ; top < n ; top++){

            for(int left = 0 ; left < n ; left++){
                if(left == top) continue;

                for(int right = 0 ; right < n ; right++){
                    if(right == left || right == top) continue;

                    for(int down = 0 ; down < n ; down++){
                        if(down == right || down == top || down == left) continue;

                        if(words[top][0] == words[left][0] && words[top][3] == words[right][0] && words[down][0] == words[left][3] && words[down][3] == words[right][3]){

                            vector<string> str;
                            str.push_back(words[top]);
                            str.push_back(words[left]);
                            str.push_back(words[right]);
                            str.push_back(words[down]);

                            ans.push_back(str);
                        }

                    }
                }
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};