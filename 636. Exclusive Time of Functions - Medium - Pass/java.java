class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] result = new int[n];
        Stack<Integer> s = new Stack<Integer>();
        
        int lastTime = 0;
        for (String log : logs) {
            String[] content = log.split(":");
            
            int task = Integer.valueOf(content[0]);
            String action = content[1];
            int time = Integer.valueOf(content[2]);
            
            int elapsedTime = action.equals("start") ? time - lastTime : time - lastTime + 1;
            lastTime = action.equals("start") ? time : time + 1;
            if (!s.isEmpty()) {
                result[s.peek()] += elapsedTime;
            }
            if (action.equals("start")) {
                s.push(task);
            } else {
                s.pop();
            }
        }
        
        return result;
    }
}