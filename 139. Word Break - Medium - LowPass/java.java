class Solution {
    private boolean searchWord(String s, int index, List<String> wordDict, boolean[] dp) {
        if (index == s.length()) {
            return true;
        }
        
        if (dp[index]) {
            return false;
        }
        
        dp[index] = true;
        for (int i = 0; i < wordDict.size(); i++) {
            if (s.startsWith(wordDict.get(i), index) && searchWord(s, index + wordDict.get(i).length(), wordDict, dp)) {
                return true;
            }
        }
        
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[305];
        Arrays.fill(dp, false);
        return searchWord(s, 0, wordDict, dp);
    }
}