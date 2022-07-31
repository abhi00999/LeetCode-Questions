class NumArray {
public:
    vector<int> segTree;
    int n;
    void build(int idx, int low, int high, vector<int> &nums){
        if(low==high){
            segTree[idx]=nums[low];
            return ;
        }
        int mid= (low+high)/2;
        build(2*idx+1, low, mid, nums);
        build(2*idx+2, mid+1, high, nums);
        segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
    }
    
    void updateTree(int idx, int low, int high, int i, int val){
        if(low==high){
            segTree[idx]=val;
            return;
        }
        
        int mid= (low+high)/2;
        if(i<=mid) updateTree(2*idx+1, low, mid, i, val);
        else updateTree(2*idx+2, mid+1, high, i, val);
        
        segTree[idx]= segTree[2*idx+1]+segTree[2*idx+2];
    }
    
    int query(int idx, int low, int high, int l, int r){
        if(high<l || r<low) return 0;
        
        if(l<=low && high<=r) return segTree[idx];
        
        int mid= (low+high)/2;
        int left= query(2*idx+1, low, mid, l, r);
        int right= query(2*idx+2, mid+1, high, l, r);
        return left+right;
    }
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree.resize(4*n,0);
        build(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
        // query(idx, )
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */