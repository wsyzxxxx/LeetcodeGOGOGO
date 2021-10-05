class Solution {
    public String boldWords(String[] words, String s) {
        boolean[] isBold = new boolean[s.length()];
        Arrays.fill(isBold, false);
        
        int matchedEnd = -1;
        for (int i = 0; i < s.length(); i++) {
            for (String word : words) {
                if (word.length() <= s.length() - i) {
                    if (s.startsWith(word, i)) {
                        matchedEnd = Math.max(i + word.length(), matchedEnd);
                    }
                }
            }
            
            if (matchedEnd > i) {
                isBold[i] = true;
            }
        }
        
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (!isBold[i]) {
                res.append(s.charAt(i));
                continue;
            }
            
            int start = i;
            while (i < s.length() && isBold[i]) {
                i++;
            }
            res.append("<b>").append(s.substring(start, i)).append("</b>");
            i--;
        }

        return res.toString();
    }
}