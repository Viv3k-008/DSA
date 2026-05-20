class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        unordered_map<int,int> mp1,mp2;


        vector<int> ans(n , 0);
        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            mp1[A[idx]]++;
            mp2[B[idx++]]++;

            int cnt = 0;
            for(auto it : mp1){
                if(mp2.count(it.first)){
                    cnt += min(it.second, mp2[it.first]);
                }
            }
            ans[i] = cnt;
        }

        return ans;
    }
};