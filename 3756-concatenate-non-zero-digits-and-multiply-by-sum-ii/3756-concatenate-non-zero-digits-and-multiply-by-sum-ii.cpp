class Solution {
public:
    int mod = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int size = s.size();
        vector<long long> prefixStr(size);
        vector<long long> prefixCnt(size);
        vector<long long> prefixSum(size);
        vector<long long> powTen;
        long long cur = 10;
        for(int i = 0 ; i < size ; i++){
            powTen.push_back(cur);
            cur = (cur*10)%mod;
        }
        int i = 0;
        long long str = 0 , cnt = 0 , sum = 0;
        for(char c : s){
            if(c == '0'){
                prefixStr[i] = str;
                prefixCnt[i] = cnt;
                prefixSum[i] = sum;
                i++;
                continue;
            }
            str = (str*10)%mod + c-'0';
            cnt++;
            prefixStr[i] = str;
            prefixCnt[i] = cnt;
            sum = (sum + c-'0')%mod;
            prefixSum[i] = sum;
            i++;
        }

        int n = queries.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            int f = queries[i][0] , s = queries[i][1];
            if(f == 0){
                int curAns = ((int)prefixStr[s]*prefixSum[s])%mod;
                ans.push_back(curAns);
            }
            else {
                
                int diff = prefixCnt[s] - prefixCnt[f-1];
                long long total = prefixStr[s] , partial = prefixStr[f-1];
                int toBeMinus = (diff == 0)? partial : (partial*powTen[diff-1])%mod;
                long long curStr = (long long) (total - toBeMinus + mod)%mod;
                int curSum = (int) (prefixSum[s]-prefixSum[f-1]);
                long long curAns = ((long long)curStr*curSum)%mod;
                ans.push_back((int) curAns);
            }
        }

        return ans;
        
    }
};