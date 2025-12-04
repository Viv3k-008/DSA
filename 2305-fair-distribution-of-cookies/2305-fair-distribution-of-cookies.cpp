class Solution {
public:
    int ans = INT_MAX;
    void fn(int i , vector<int>& cookies , vector<int>& store , int k){
        if(i == cookies.size()){
            int curAns = 0;
            for(int t : store){
                curAns = max(curAns , t);
            }
            ans = min(ans , curAns);
            return;
        }

        for(int child = 0 ; child < k ; child++){
            store[child] += cookies[i];

            if(store[child] < ans){
                fn(i+1 , cookies , store , k);
            }
            store[child] -= cookies[i];

            if (store[child] == 0) break;
        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k , 0);
        sort(cookies.rbegin() , cookies.rend());
        fn(0 , cookies , temp , k);

        return ans;
    }
};