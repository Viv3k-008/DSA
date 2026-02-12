class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string , bool> mp;
        for(string s : wordList){
            mp[s] = true;
        }

        if(!mp.count(endWord)) return 0;
        queue<pair<string,int>> q;

        q.push({beginWord , 1});

        while(!q.empty()){
            auto it = q.front();
            string cur = it.first;
            int len = it.second;

            q.pop();

            if(cur == endWord) return len;
            for(int i = 0 ; i < cur.size() ; i++){
                char original = cur[i];

                for(char c = 'a' ; c <= 'z' ; c++){
                    cur[i] = c;

                    if(mp.count(cur)){
                        q.push({cur , len+1});
                        mp.erase(cur);
                    }
                    
                }

                cur[i] = original;
            }
        }


        return 0;

    }
};