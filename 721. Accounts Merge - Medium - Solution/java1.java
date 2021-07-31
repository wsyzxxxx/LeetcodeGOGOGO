class Solution {
    private void addAllToList(Set<String> emailSt, int index, boolean[] visited, List<Set<String>> emails) {
        for (String email : emails.get(index)) {
            if (!emailSt.contains(email)) {
                emailSt.add(email);
            }
            
            for (int i = 0; i < emails.size(); i++) {
                if (!visited[i] && emails.get(i).contains(email)) {
                    visited[i] = true;
                    
                    addAllToList(emailSt, i, visited, emails);
                }
            }
        }
    }
    
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        List<String> names = new ArrayList<>();
        List<Set<String>> emails = new ArrayList<>();
        for (List<String> account : accounts) {
            names.add(account.get(0));
            
            Set<String> st = new HashSet<>();
            for (int i = 1; i < account.size(); i++) {
                st.add(account.get(i));
            }
            emails.add(st);
        }
        
        boolean[] visited = new boolean[names.size()];
        Arrays.fill(visited, false);
        
        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < names.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                Set<String> emailSt = new TreeSet<>();
                addAllToList(emailSt, i, visited, emails);
                
                List<String> resultItem = new ArrayList<>();
                resultItem.add(names.get(i));
                resultItem.addAll(emailSt);
                result.add(resultItem);
            }
        }
        
        return result;
    }
}