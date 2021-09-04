class NumArray {
    private int[] tree;
    private int n;
    
    private void buildTree(int[] nums) {
        this.tree = new int[2 * n];
        
        for (int i = 0; i < n; i++) {
            this.tree[i+n] = nums[i];
        }
        for (int i = n-1; i >= 0; i--) {
            this.tree[i] = this.tree[i * 2] + this.tree[i * 2 + 1];
        }
    }
    
    public NumArray(int[] nums) {
        this.n = nums.length;
        buildTree(nums);
    }
    
    public void update(int index, int val) {
        this.tree[index+n] = val;
        int i = index+n;
        while (i > 0) {
            this.tree[i/2] = this.tree[i/2*2] + this.tree[i/2*2+1];
            i /= 2;
        }
    }
    
    public int sumRange(int left, int right) {
        int sum = 0;
        left += n;
        right += n;
        while (left < right) {
            if (left % 2 != 0) {
                sum += this.tree[left];
                left = left / 2 + 1;
            } else {
                left /= 2;
            }
            if (right % 2 == 0) {
                sum += this.tree[right];
                right = right / 2 - 1;
            } else {
                right /= 2;
            }
        }
        
        if (left == right) {
            sum += this.tree[left];
        }
        //sum += this.tree[left];
        return sum;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */