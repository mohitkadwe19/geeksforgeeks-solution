class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
      data = item;
      left = right = null;
    }
}

class Solution {
    
    Map<String, Integer> mp = new HashMap<>();

    String recur (Node root){
        if(root ==null){
            return "$";
        }
        String s = "";
        if(root.left==null && root.right==null){
            s+=root.data;
            return s;
        }
        s+=root.data;
        s+=recur(root.left);
        s+=recur(root.right);
         mp.put(s,mp.getOrDefault(s,0)+1);
         return s;
    }
    int dupSub(Node root) {
        // code here 
        recur(root);
        for(Integer num : mp.values()){
            
            if(num >=2){
                return 1;
            }   
        }
        return 0;
    }
}