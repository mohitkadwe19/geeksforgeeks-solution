import java.io.*;
import java.util.*;

class Node
{
    int data;
    Node next, prev;
    Node(int data)
    {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
};

public static Node reverseDLL(Node  head)
{

    if(head == null || head.next == null)
    {
        return head;
    }

    Node curr = head;
    Node prev = null;
    Node next = null;

    while(curr != null)
    {
        next = curr.next;
        curr.next = prev;
        curr.prev = next;

        prev = curr;
        curr = next;
    }

    head = prev;

    return head;
}