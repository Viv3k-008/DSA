class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;

        int days = 0;
        int idx = 0;
        int event = 0;

        while( idx < n|| !pq.empty()){
            if(pq.empty()){
                days = events[idx][0];
            }

            while(idx < n && days == events[idx][0]){
                pq.push(events[idx++][1]);
            }

            while(!pq.empty() && days > pq.top()){
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                event++;
            }
            days++;
        }

        return event;
    }
};