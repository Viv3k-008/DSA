class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        stack<int> stk;

        vector<int> vec(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(stk.empty()){
                stk.push(i);
                continue;
            }

            if(s[i] == ')' && s[stk.top()] == '('){
                vec[stk.top()] = 1;
                vec[i] = 1;
                stk.pop();
            }
            else stk.push(i);
        }

        int cnt = 0 , maxi = 0;

        for(int i : vec){
            if(i == 1){
                cnt++;
                maxi = max(cnt , maxi);
            }
            else cnt = 0;
        }

        return maxi;
    }
};