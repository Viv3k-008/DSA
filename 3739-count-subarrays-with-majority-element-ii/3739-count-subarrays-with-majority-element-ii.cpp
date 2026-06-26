class Solution {
public:
    /*
        we can create the comutative sum -
        which is if nums[i] == target then cumSum ++;
        else cumSum --;

        it is like moore voting algorithm to find the majority element.

        we will create a array of comutative sum.
        then to find a subarray (i to j) where the target is in majority

        simply (cumSum[j] - cumSum[i-1]) > 0 (according to moore voting algo)
        we can write it in -> cumSum[j] > cumSum[i-1]

        so if we can find the no of cumSum[i-1] which are less than cumSum[j] will be
        only our ans for the subarray(i to j)

        Algorithm-

        So we are creating the cumSum for every index.
        And we have created the unordered_map to store the cumSum , so that we can 
        get the count of any cumSum.
        In validLeftPoints we are calculating the valid points or cumSum which are less
        than the current curSum.
        then if(target == nums[i])
                so we can store the previous curSum count in the validLeftPoint
                then we can cumSum++.
            else 
                We will first cumSum--
                Then we will have to reduce the validLeftPoint to validLeftPoint - mp[cumSum] , because the validLeftSum contains the reduced sumSum count also.
            
            now we will mp[cumSum]++;
            then we can add validLeftPoints to the results. (in validLeftPoints their are all the valid points which are less than the cumSum)

        can refer this video for dry run - https://youtu.be/d8gBjEG6Ouc?si=vTpDFieb1_FwuEgo
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