class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // [1,1,1,4,5,6] -> [1,4,1,5,1,6]
        // [1,1,2,2,3,3,5] -> [1,3,1,3,2,5,2]

        int n = nums.size() , size = 0;

        if(n%2) size = n/2+1;
        else size = n/2;

        sort(nums.begin(),nums.end());

        vector<int> first, sec;
        for(int i = 0 ; i < size; i++) first.push_back(nums[i]);

        for(int i = size; i < n ; i++) sec.push_back(nums[i]);

        for(int i : first) cout<<i<<" ";
        cout<<endl;
        for(int i : sec) cout<<i<<" ";

        int l = first.size()-1, m = sec.size()-1;
        for(int i = 0 ; i < n ; i++){
            if(i%2){
                nums[i] = sec[m--];
            }
            else nums[i] = first[l--];
        }

    }
};