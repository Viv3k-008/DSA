class Solution {
public:
    void reduce(vector<int>& turn, int n, int val){
        for(int i = 0 ; i < 26 ; i++){
                if(turn[i] > 0){
                    turn[i]--;
                }
            }
            if(val != -1) turn[val] = n;
    }
    static bool comp(const pair<int,int> a,const pair<int,int> b) {
        return a.second > b.second;
    }

    int leastInterval(vector<char>& tasks, int n) {
        // A -> B -> IDLE -> IDLE -> A -> B -> IDLE -> IDLE -> A -> B

        multiset<pair<int,int>, decltype(&comp)> alpha(comp);

        unordered_map<int,int> cur;

        for(char i : tasks) cur[i-'A']++;

        int cnt = 0;
        for(auto it : cur) alpha.insert(it), cnt += it.second;

        vector<int> turn(26,0);

        int ans = 0;
        while(cnt){
            int val = -1;
            bool notFound = true;
           for(auto it = alpha.begin(); it != alpha.end(); ++it) {

                int character = it->first;
                int frequency = it->second;

                if(turn[character] == 0) {

                    notFound = false;
                    val = character;
                    alpha.erase(it);
                    frequency--;
                    cnt--;
                    if(frequency > 0) {
                        alpha.insert({character, frequency});
                    }

                    break;
                }
            }
            if(notFound){
                ans++;
                reduce(turn, n, -1);
                continue;
            }

            ans++;
            reduce(turn, n, val);
        }

        return ans;

    }
};