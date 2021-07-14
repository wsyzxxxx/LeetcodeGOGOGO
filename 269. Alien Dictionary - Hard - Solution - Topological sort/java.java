class Solution {
    public String alienOrder(String[] words) {
        int[] in = new int[26];
        for (int i = 0; i < 26; i++) {
            in[i] = 0;
        }
        
        Map<Character, Set<Character>> mp = new HashMap<Character, Set<Character>>();
        for (int i = 0; i < words.length; i++) {
            for (int k = 0; k < words[i].length(); k++) {
                if (!mp.containsKey(words[i].charAt(k))) {
                    mp.put(words[i].charAt(k), new HashSet<Character>());
                }
            }
        }
        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (words[i].length() > words[j].length() && words[i].startsWith(words[j])) {
                    return "";
                }
                for (int k = 0; k < words[i].length() && k < words[j].length(); k++) {
                    if (words[i].charAt(k) != words[j].charAt(k)) {
                        if (!mp.containsKey(words[i].charAt(k))) {
                            mp.put(words[i].charAt(k), new HashSet<Character>());
                        }
                        if (!mp.get(words[i].charAt(k)).contains(words[j].charAt(k))) {
                            in[words[j].charAt(k) - 'a']++;
                        }
                        mp.get(words[i].charAt(k)).add(words[j].charAt(k));
                        break;
                    }
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        Queue<Character> queue = new LinkedList<>();
        for (int i = 0; i < 26; i++) {
            char key = (char)(i + 'a');
            if (mp.containsKey(key) && in[i] == 0) {
                in[i]--;
                queue.offer(key);
            }
        }
        
        while (!queue.isEmpty()) {
            char c = queue.poll();
            
            sb.append(c);
            
            for (char v : mp.getOrDefault(c, new HashSet<>())) {
                in[v - 'a']--;
                if (in[v - 'a'] == 0) {
                    in[v - 'a']--;
                    queue.offer(v);
                }
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (in[i] > 0) {
                return "";
            }
        }
                                                       
        return sb.toString();
    }
}