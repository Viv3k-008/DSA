public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int n = nums.Length;

        Dictionary<int,int> dt = new Dictionary<int,int>();
        for(int i = 0 ; i < n ; i++){
            if(dt.ContainsKey(target-nums[i])){
                return new int[] {i, dt[target-nums[i]]};
            }
            dt[nums[i]] = i;
        }

        return new int[] {-1, -1};
    }
}