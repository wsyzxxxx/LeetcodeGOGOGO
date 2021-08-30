class Solution {
    private class Job {
        public int start;
        public int end;
        public int pro;
        
        public Job(int _s, int _e, int _p) {
            this.start = _s;
            this.end = _e;
            this.pro = _p;
        }
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        List<Job> jobList = new ArrayList<>();
        for (int i = 0; i < startTime.length; i++) {
            jobList.add(new Job(startTime[i], endTime[i], profit[i]));
        }
        
        jobList.sort((Job job1, Job job2) -> {
            if (job1.start == job2.start) {
                return job1.end - job2.end;
            }
            return job1.start - job2.start;
        });
        
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(
            new Comparator<Pair<Integer, Integer>> () {
                @Override
                public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
                    return a.getKey() - b.getKey();
                }
            }
        );
        
        int maxProfit = 0;
        for (int i = 0; i < jobList.size(); i++) {
            int s = jobList.get(i).start;
            int e = jobList.get(i).end;
            int p = jobList.get(i).pro;
            
            while (!pq.isEmpty() && s >= pq.peek().getKey()) {
                maxProfit = Math.max(maxProfit, pq.peek().getValue());
                //System.out.println("remo: " + pq.peek().getValue());
                pq.remove();
            }
            
            //System.out.println("curr: " + e + " " + (p+maxProfit));
            pq.add(new Pair<>(e, p + maxProfit));
        }
        
        while (!pq.isEmpty()) {
            maxProfit = Math.max(maxProfit, pq.peek().getValue());
            pq.remove();
        }
        
        return maxProfit;
    }
}