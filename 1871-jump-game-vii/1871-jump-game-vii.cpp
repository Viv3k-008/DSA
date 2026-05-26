class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1')
            return false;

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int far = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();

            if(top == n - 1)
                return true;

            int start = max(far+1 , top+minJump);
            int end = min(top+maxJump , n-1);
            for(int k = start ; k <= end ; k++) {
                if (s[k] == '0' && !vis[k]) {
                    vis[k] = true;
                    q.push(k);
                }
            }

            far = end;
        }

        return false;
    }
};
