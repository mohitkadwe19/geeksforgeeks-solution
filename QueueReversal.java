import java.util.*;
import java.io.*;

class GfG{
    //Function to reverse the queue.
    public Queue<Integer> rev(Queue<Integer> q){
        Stack<Integer>st=new Stack<>();
        while(!q.isEmpty()){
        st.push(q.poll());
        }
         while(!st.isEmpty())
        {
        q.add(st.pop());
        }
        return q;
    }
}


public class QueueReversal {
   public static void main(String []args) {
       Queue<Integer> q=new LinkedList<>();
       q.add(1);
       q.add(2);
       q.add(3);
       q.add(4);
       q.add(5);
       GfG ob=new GfG();
       Queue<Integer> q1=ob.rev(q);
       while(!q1.isEmpty())System.out.print(q1.poll()+" ");
   }
}