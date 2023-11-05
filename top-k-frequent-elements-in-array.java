import java.util.HashMap;
import java.util.PriorityQueue;

class Solution {
    public int[] topK(int[] nums, int k) {
      HashMap<Integer, Integer> map = new HashMap<>();
      for (int i = 0; i < nums.length; i++) {
        map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
      }
        
      PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
        
            if(map.get(a) == map.get(b)){
                return b-a;
            }
            
            return map.get(b) - map.get(a);
        });
    
        for(int num: map.keySet()){
            pq.add(num);
        }
    
        int output[] = new int[k];
        for(int i = 0; i<k; i++){
            output[i] = pq.poll();
        }
        
        return output;
    }
}