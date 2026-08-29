class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        unordered_map<int,list<int>> groupToNum;
        unordered_map<int,int> group;

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int g = 0;
        groupToNum[g].push_back(temp[0]);
        group[g] = temp[0];
        for(int i = 1 ; i < n; i++){
            if(abs(temp[i]-temp[i-1]) > limit){
                g++;
            }
            
            groupToNum[g].push_back(temp[i]);
            group[temp[i]] = g;
        }

        for(int i = 0 ; i < n ; i++){
            int g = group[nums[i]];
            if(groupToNum[g].size() == 0) continue;

            nums[i] = *(groupToNum[g].begin());
            groupToNum[g].pop_front();
        }

        return nums;

    }
};