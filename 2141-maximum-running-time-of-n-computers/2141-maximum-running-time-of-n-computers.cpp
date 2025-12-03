class Solution {
public:
    long long check(long long time , vector<int>& b , int n){
        
        long long contri = 0;

        for(int i : b){
            contri += min(1LL*i , time);
            if(contri >= time*n){
                return true;
            }
        }

        return false;
        
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        int size = batteries.size();

        sort(batteries.begin() , batteries.end());
        long long low = 0 , high = 1e14 , ans = 0;

        while(low <= high){
            long long mid = low+(high-low)/2;

            if(check(mid , batteries , n)){
                low = mid+1;
                ans = mid;
            }
            else high = mid-1;
        }


        return ans;
    }
};