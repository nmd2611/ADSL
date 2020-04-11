package Specific;

import Common.CommonList;
import java.util.*;

class Node {

    int data;
    Node next;

    Node() {
        data = 0;
        next = null;
    }
}

public class SLL implements CommonList {

    Node first;

    SLL() {
        first = null;
    }

    @Override
    public void add(int x) {
        Node newN = new Node();
        Node temp = new Node();

        newN.data = x;
        newN.next = null;

        if (first == null) {
            first = newN;
            System.out.println("First element added");
            return;
        }
        temp = first;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newN;

        System.out.println(" Element added !!");

    }

    @Override
    public void remove(int x) {
        Node p, q = new Node();

        if (first.data == x) {
            // delete first node
            p = first;
            first = first.next;
            p.next = null;
            p = null;
            System.out.println("Element deleted");
            return;
        }

        p = first;
        q = first.next;

        while (q != null) {
            if (q.data == x) {
                Node temp = new Node();
                temp = q;
                p.next = q.next;
                q.next = null;

                temp = null;
                break;
            }

            p = q;
            q = q.next;

        }

    }

    @Override
    public int size() {
        int cnt = 0;

        Node p = new Node();
        p = first;

        while (p != null) {
            p = p.next;
            cnt++;
        }
        return cnt;

    }

    @Override
    public boolean isEmpty() {
        if (first == null)
            return true;
        else
            return false;

    }

    @Override
    public void display() {
        Node p = new Node();
        p = first;
        while (p != null) {
            System.out.print(p.data + "\t");
            p = p.next;
        }
        System.out.println();

    }

    public static void main(String args[]) {
        SLL obj = new SLL();

        obj.add(10);
        obj.add(20);
        obj.add(30);
        obj.add(40);
        obj.add(50);
        System.out.println(obj.size());
        obj.remove(10);
        obj.remove(30);
        obj.display();

        if (obj.isEmpty())
            System.out.println("list is Empty");
        else
            System.out.println("List is Not Empty");
    }

}
