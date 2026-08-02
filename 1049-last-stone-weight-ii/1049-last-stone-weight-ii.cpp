class Solution {
public:
    unordered_map<int, int> memo;
    
    int dp(int i, int curSum, vector<int>& stones, int half, 
           vector<vector<int>>& memo){
        if(i == stones.size() || curSum == half){
            return curSum;
        }
        if(memo[i][curSum] != -1) return memo[i][curSum];
        
        int op1 = -1e9; 
        
        if(curSum + stones[i] <= half){
            op1 = dp(i+1, curSum + stones[i], stones, half, memo); 
        }
        int op2 = dp(i+1, curSum, stones, half, memo); 
        
        return memo[i][curSum] = max(op1, op2);
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int half = total / 2;
        int n = stones.size();
        
        vector<vector<int>> memo(n, vector<int>(half + 1, -1));
        
        int s1 = dp(0, 0, stones, half, memo);
        
        return total - 2 * s1;
    }
};