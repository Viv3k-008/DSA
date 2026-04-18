class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();

        sort(g.begin() , g.end());
        priority_queue<int , vector<int> , greater<int>> pq;

        int cnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            pq.push(s[i]);
        }


        for(int i = 0 ; i < n ; i++){
            while(!pq.empty() && (g[i] > pq.top())){
                pq.pop();
            }

            if(!pq.empty() && g[i] <= pq.top()) {
                pq.pop();
                cnt++;
            }
        }

        return cnt;
    }
};