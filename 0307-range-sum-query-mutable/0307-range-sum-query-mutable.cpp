class NumArray {
public:
    int n;
    vector<int> segArr;
    void build(int l , int r , int idx , vector<int>& nums , vector<int>& segArr){
        if(l == r){
            segArr[idx] = nums[l];
            return;
        }

        int mid = l+(r-l)/2 , left = 2*idx+1 , right = 2*idx+2;
        build(l , mid , left , nums , segArr);
        build(mid+1 , r , right , nums , segArr);

        segArr[idx] = segArr[left] + segArr[right];

    }
    void update(int l , int r , int idx , int i , int val , vector<int>& segArr){
        if(l == r){
            segArr[idx] = val;
            return;
        }

        int mid = l+(r-l)/2 , left = 2*idx+1 , right = 2*idx+2;

        if(i <= mid) update(l , mid , left , i , val , segArr);
        else if(i > mid) update(mid+1 , r , right , i , val , segArr);

        segArr[idx] = segArr[left] + segArr[right];
    }
    int sumQuery(int l , int r , int ql , int qr , int idx , vector<int>& segArr){
        if(r < ql || qr < l){
            return 0;
        }
        else if(ql <= l && r <= qr) return segArr[idx];

        int mid = l+(r-l)/2 , left = 2*idx+1 , right = 2*idx+2;

        int op1 = sumQuery(l , mid , ql , qr , left , segArr);
        int op2 = sumQuery(mid+1 , r , ql , qr , right , segArr);

        return op1 + op2;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();

        segArr.assign(4*n , 0);

        build(0 , n-1 , 0 , nums , segArr);
    }
    
    void update(int index, int val) {
        update(0 , n-1 , 0 , index , val , segArr);
    }
    
    int sumRange(int left, int right) {
        return sumQuery(0 , n-1 , left , right , 0 , segArr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */