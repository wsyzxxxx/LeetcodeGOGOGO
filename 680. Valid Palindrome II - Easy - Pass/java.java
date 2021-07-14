class Solution {
    private boolean isPalindrome(String s, int left, int right, boolean removeOne) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                if (!removeOne) {
                    return isPalindrome(s, left+1, right, true) || isPalindrome(s, left, right-1, true);
                } else {
                    return false;
                }
            }
            left++;
            right--;
        }
        
        return left >= right;
    }
    public boolean validPalindrome(String s) {
        return isPalindrome(s, 0, s.length() - 1, false);
    }
}