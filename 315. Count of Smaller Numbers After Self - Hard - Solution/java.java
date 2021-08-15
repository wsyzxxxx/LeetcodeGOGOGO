class Solution {
    private void mergeSort(List<Integer> result, int[] nums, int[] indices, int start, int end) {
        if (start >= end) {
            return;
        }
        
        int mid = (start + end) / 2;
        
        mergeSort(result, nums, indices, start, mid);
        mergeSort(result, nums, indices, mid+1, end);
        
        List<Integer> temp = new ArrayList<>();
        for (int i = start, j = start, k = mid+1; i <= end; i++) {
            if (j == mid+1) {
                temp.add(indices[k++]);
            } else if (k == end+1) {
                temp.add(indices[j++]);
            } else {
                if (nums[indices[j]] > nums[indices[k]]) {
                    temp.add(indices[j]);
                    result.set(indices[j], result.get(indices[j]) + end - k + 1);
                    j++;
                } else {
                    temp.add(indices[k++]);
                }
            }
        }
        
        for (int i = 0; i < temp.size(); i++) {
            indices[start+i] = temp.get(i);
        }
    }
    
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            result.add(0);
        }
        
        int[] indices = new int[nums.length];
        for (int i = 0; i < indices.length; i++) {
            indices[i] = i;
        }
        
        mergeSort(result, nums, indices, 0, nums.length-1);

        // for (int i = 0; i < indices.length; i++) {
        //     System.out.print(nums[indices[i]] + " " );
        // }
        // System.out.println();
        return result;
    }
}