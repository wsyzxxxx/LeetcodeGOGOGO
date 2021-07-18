class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> results = new ArrayList<>();
        
        List<List<StringBuilder>> dp = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            dp.add(new ArrayList<>());
        }
        dp.add(new ArrayList<>());
        
        for (String word : wordDict) {
            if (s.startsWith(word)) {
                dp.get(word.length()).add(new StringBuilder(word));
            }
        }
        
        for (int i = 1; i < s.length(); i++) {
            for (String word : wordDict) {
                if (s.startsWith(word, i)) {
                    for (int k = 0; k < dp.get(i).size(); k++) {
                        dp.get(i + word.length()).add(new StringBuilder(dp.get(i).get(k)).append(" ").append(word));
                    }
                }
            }
        }
        
        List<String> result = new ArrayList<>();
        for (StringBuilder sb : dp.get(s.length())) {
            result.add(sb.toString());
        }
        
        return result;
    }
}