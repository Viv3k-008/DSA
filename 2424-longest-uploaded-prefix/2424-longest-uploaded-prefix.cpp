class LUPrefix {
public:
    int lon , n;
    vector<int> nums;
    LUPrefix(int m) {
        nums.assign(m , 0);
        lon = -1;
        n = m;
    }
    
    void upload(int video) {
        nums[video-1]++;
        while(lon+1 < n && nums[lon+1]){
            lon++;
        }
    }
    
    int longest() {
        return lon+1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */