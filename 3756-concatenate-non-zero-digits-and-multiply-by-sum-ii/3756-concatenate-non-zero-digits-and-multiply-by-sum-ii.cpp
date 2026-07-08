class Solution {
public:
    int MOD = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pow(n);
        for(int i = 0 ; i < n ; i++){
            if(i == 0) pow[i] = 10;
            else pow[i] = ((pow[i-1])%MOD*10)%MOD;
        }

        vector<long long> prefixSum(n), prefixLen(n), prefixStr(n);
        long long sum = 0, str = 0, len = 0;

        for(int i = 0 ; i < n ; i++){
            long long val = (long long)(s[i]-'0');

            if(val == 0){
                prefixStr[i] = str;
                prefixSum[i] = sum;
                prefixLen[i] = len;
            }
            else {
                str = (str * 10)%MOD;
                str = (str+val)%MOD;
                prefixStr[i] = str;
                sum = (sum+val)%MOD;
                prefixSum[i] = sum;
                len++;
                prefixLen[i] = len;
            }
        }

        vector<int> ans;
        int m = queries.size();
        for(int i = 0 ; i < m ; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            long long curAns = 0;
            if(l == 0){
                curAns = ((prefixStr[r])*(prefixSum[r]))%MOD;
                ans.push_back((int)curAns);
            }
            else{
                long long incNum = prefixStr[r], exclNum = prefixStr[l-1], xLen = (prefixLen[r] - prefixLen[l-1]);
                int querySum = (int)(prefixSum[r] - prefixSum[l-1]);

                int toBeMinus = (exclNum%MOD  * ((xLen == 0)? 1 : pow[xLen-1])%MOD)%MOD;

                int reqNum = (int)(incNum - toBeMinus + MOD)%MOD;

                curAns = ((long long)reqNum * querySum)%MOD;
                ans.push_back((int)curAns);
            }
        }

        return ans;
    }
};