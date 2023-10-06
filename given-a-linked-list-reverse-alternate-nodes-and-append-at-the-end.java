
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Solution
{
    public static void rearrange(Node odd)
    {
      if(odd==null || odd.next==null){
          return;
      }
      
       Node even=odd.next;
       Node temp=even;
       
       while(odd.next!=null && even.next!=null){
           odd.next=even.next;
           odd=even.next;
           even.next=odd.next;
           even=odd.next;
       }
       
        Node curr=temp;
        Node prev=null;
        while(curr!=null){
            Node nextNode=curr.next;
            curr.next=prev;
            
            prev=curr;
            curr=nextNode;
        }
        
        odd.next=prev;
    }
    public static void main(String[] args){
      Node solution = new Node(1);
      Node solution.next = new Node(2);
      Node solution.next.next = new Node(3);
      Node solution.next.next.next = new Node(4);
      rearrange(solution);
      while(solution!=null)
      {
          System.out.println(solution.data);
          solution = solution.next;
      } 
    }
}