class MapSum {
    private class Trie {
        public class Node {
            public int value;
            public Node[] nodes;
            public Node() {
                value = 0;
                nodes = new Node[26];
                Arrays.fill(nodes, null);
            }
        }
        
        private Node root;
        private Map<String, Integer> pairs;
        
        public Trie() {
            root = new Node();
            pairs = new HashMap<String, Integer>();
        }
        
        public void addNewPair(String key, int val) {
            int remove = 0;
            if (pairs.containsKey(key)) {
                remove = pairs.get(key);
            }
            Node curr = root;
            for (int i = 0; i < key.length(); i++) {
                curr.value += val - remove;
                if (curr.nodes[key.charAt(i) - 'a'] == null) {
                    curr.nodes[key.charAt(i) - 'a'] = new Node();
                }
                
                curr = curr.nodes[key.charAt(i) - 'a'];
            }
            curr.value += val - remove;
            
            pairs.put(key, val);
        }
        
        public int getSum(String prefix) {
            Node curr = root;
            for (int i = 0; i < prefix.length(); i++) {
                curr = curr.nodes[prefix.charAt(i) - 'a'];
                if (curr == null) {
                    return 0;
                }
            }
            
            return curr.value;
        }
    }
    
    private Trie trie;
    /** Initialize your data structure here. */
    public MapSum() {
        trie = new Trie();
    }
    
    public void insert(String key, int val) {
        trie.addNewPair(key, val);
    }
    
    public int sum(String prefix) {
        return trie.getSum(prefix);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */