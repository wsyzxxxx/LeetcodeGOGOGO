class Solution {
    int[] parents;
    
    int getParent(int x) {
        if (parents[x] != x) {
            parents[x] = getParent(parents[x]);
        }
        
        return parents[x];
    }
    
    void conn(int x, int y) {
        parents[getParent(x)] = getParent(y);
    }
    
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, Integer> emailToID = new HashMap<>();
        Map<String, Integer> emailToIndex = new HashMap<>();
        
        parents = new int[10005];
        for (int i = 0; i < parents.length; i++) {
            parents[i] = i;
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            List<String> account = accounts.get(i);
            for (int j = 1; j < account.size(); j++) {
                if (!emailToID.containsKey(account.get(j))) {
                    emailToID.put(account.get(j), emailToID.size());
                    emailToIndex.put(account.get(j), i);
                }
                
                if (getParent(emailToID.get(account.get(1))) != getParent(emailToID.get(account.get(j)))) {
                    conn(emailToID.get(account.get(j)), emailToID.get(account.get(1)));
                }
            }
        }
        
        List<List<String>> result = new ArrayList<>();
        Map<Integer, Integer> parentToResult = new HashMap<>();
        emailToID.forEach((k, v) -> {
            int parent = getParent(v);
            
            if (!parentToResult.containsKey(parent)) {
                result.add(new ArrayList<>());
                parentToResult.put(parent, result.size()-1);
            }
            
            result.get(parentToResult.get(parent)).add(k);
        });
        for (List<String> resultItem : result) {
            Collections.sort(resultItem);
            resultItem.add(0, accounts.get(emailToIndex.get(resultItem.get(0))).get(0));
        }
        
        return result;
    }
}