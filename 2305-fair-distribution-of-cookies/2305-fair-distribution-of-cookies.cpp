class Solution {
public:
    int ans = INT_MAX;
    void fn(int i, int n, vector<int>& store, vector<int>& c , int k){
        if(i == n){
            int cur = INT_MIN;
            for(int c : store){
                cur = max(cur, c);
            }
            ans = min(ans, cur);
            return;
        }


        for(int p = 0 ; p < k ; p++){
            store[p] += c[i];
            if(store[p] < ans){
                fn(i+1, n, store, c, k);
            }

            store[p] -= c[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        sort(cookies.begin(),cookies.end());
        vector<int> store(k, 0);
        fn(0, n, store, cookies, k);

        return ans;
    }
};