class Solution {
public:
    /*
            we can create the comutative sum -
            which is if nums[i] == target then cumSum ++;
                     else cumSum --;
            
            it is like moore voting algorithm to find the majority element.

            we will create a array of comutative sum.
            then to find a subarray (i to j) where the target is in majority

            simply cumSum[j] - cumSum[i-1] > 0 (according to moore voting algo)
            we can write it in -> cumSum[j] > cumSum[i-1]

            so if we can find the no of cumSum[i-1] which are less than cumSum[j] will be 
            only our ans for the subarray(i to j)

            can refer this video - https://www.youtube.com/watch?v=d8gBjEG6Ouc&t=2244s
    */
    
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        
        int n = nums.size();

        long long validLeftPts = 0 , cumSum = 0 , result = 0;

        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == target){
                validLeftPts += mp[cumSum];
                cumSum ++;
            }
            else {
                cumSum --;
                validLeftPts -= mp[cumSum];
            }

            mp[cumSum] ++;
            result += validLeftPts;
        }

        return result;
    }
};