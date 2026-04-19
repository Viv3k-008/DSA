class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,int> mp;

        for(int i = 0 ; i < n ; i++){
            mp[wordList[i]] = i;
        }

        queue<pair<string , int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            if(it.first == endWord) return it.second;

            string str = it.first;
            int len = it.second;
            for(int i = 0 ; i < it.first.size() ; i++){
                char original = str[i];

                for(char c = 'a' ; c <= 'z' ; c++){

                    str[i] = c;
                    if(mp.count(str)){
                        q.push({str , len+1});
                        mp.erase(str);
                    }
                }

                str[i] = original;
            }
        }

        return 0;
    }
};