class Node {
   int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}

class Solution
{
   public static Node findIntersection(Node head1, Node head2)
    {
        //code here
        Node x = head1, y = head2, res=null,head=null;

        while(x!=null && y!=null){

            if(x.data<y.data)

                x = x.next;

            else if(x.data>y.data)

                y = y.next;

            else{

                Node t = new Node(x.data);

                if(head==null)

                    head = t;

                else

                    res.next=t;

                res = t;

                y = y.next;

                x = x.next;

            }
        }
        return head;
    }
}