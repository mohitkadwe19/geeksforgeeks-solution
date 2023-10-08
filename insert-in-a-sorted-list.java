class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }

// sortedInsert method should return the head of the modified linked list.
class Solution {
    Node sortedInsert(Node head1, int key) {
        if(head1 == null || head1.data > key){
            Node head = new Node(key);
            head.next = head1;
            return head;
        }
        
        Node prev = null;
        Node curr = head1;
        
        while(curr!= null && curr.data <= key){
            prev = curr;
            curr = curr.next;
        }
        
        if(curr == null){
            Node node = new Node(key);
            prev.next = node;
        }
        else{
            Node node = new Node(key);
            prev.next = node;
            node.next = curr;
        }
        return head1;
    }
    public static void main(String[] args){
        Node solution = new Node(1);
        Node.solution.next = new Node(2);
        Node.solution.next.next = new Node(3);
        Node.solution.next.next.next = new Node(4);
        solution.sortedInsert(solution, 5);
        while(solution!=null)
        {
            System.out.println(solution.data);
            solution = solution.next;
        }
    }
}