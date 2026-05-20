class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        q.push({startGene,0});

        unordered_map<string,bool> mp;
        for(string it : bank) mp[it] = true;
        char ch[4] = {'A','C','G','T'};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            string curStr = it.first;
            int steps = it.second;

            if(curStr == endGene) return steps;

            for(int k = 0 ; k < curStr.size() ; k++){
                char original = curStr[k];

                for(int j = 0 ; j < 4 ; j++){
                    curStr[k] = ch[j];
                    if(mp.count(curStr)){
                        q.push({curStr,steps+1});
                        mp.erase(curStr);
                    }
                }
                curStr[k] = original;
            }
        }
        return -1;
    }
};