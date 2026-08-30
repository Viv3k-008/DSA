class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        pair<int,int> num = {-1e9,1e9};
        for(int i : nums){
            num.first = max(num.first,i);
            num.second = min(num.second,i);
        }

        int ways = 1e9;

        int cnt = 0;
        pair<bool,bool> flag = {false,false};
        // left to right
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num.first){
                flag.first = true;
            }
            else if(nums[i] == num.second){
                flag.second = true;
            }
            cnt++;
            if(flag.first && flag.second) break;
        }
       
        ways = cnt;

        // right to left
        cnt = 0;
        flag = {false,false};
        for(int i = n-1; i >= 0 ; i--){
            if(nums[i] == num.first){
                flag.first = true;
            }
            else if(nums[i] == num.second){
                flag.second = true;
            }
            cnt++;
            if(flag.first && flag.second) break;
        }
       
        ways = min(ways, cnt);

        // both sides
        cnt = 0;
        flag = {false,false};
        int i = 0;
        while(i < n){
            if(nums[i] != num.first && nums[i] != num.second){
                i++;
                cnt++;
            }
            else {
                cnt++;
                break;
            }
        }
        i = n-1;
        while(i >= 0){
            if(nums[i] != num.first && nums[i] != num.second){
                i--;
                cnt++;
            }
            else {
                cnt++;
                break;
            }
        }
        
        ways = min(ways, cnt);


        return ways;
    }
};