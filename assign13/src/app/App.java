package app;

import java.util.*;

public class App {

    public static void LL() {
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> l = new LinkedList<Integer>();
        int ch;
        int x;
        do {
            System.out.println(
                    "1.Add First \n 2.Add Last \n 3.Remove First \n 4.Remove Last \n 5.Size \n 6.Display List \n 7.Exit");
            ch = sc.nextInt();

            switch (ch) {
                case 1:
                    System.out.println("Enter element to be added");
                    x = sc.nextInt();
                    l.addFirst(x);
                    break;

                case 2:
                    System.out.println("Enter element to be added");
                    x = sc.nextInt();
                    l.addLast(x);
                    break;

                case 3:
                    l.removeFirst();
                    System.out.println("Element deleted");
                    break;

                case 4:
                    l.removeLast();
                    System.out.println("Element deleted");
                    break;

                case 5:
                    System.out.println("Size of List : " + l.size());
                    break;

                case 6:
                    System.out.println("List : " + l);
                    break;

                case 7:
                    break;

                default:
                    System.out.println("Wrong Choice !!");
                    break;
            }
        } while (ch != 7);

        sc.close();
    }

    public static void Hash() {
        Scanner sc = new Scanner(System.in);
        HashSet<Integer> h = new HashSet<Integer>();

        int ch, x;
        do {
            System.out.println(" 1.Add \n 2.Remove \n 3.Contains \n 4. Display List \n 5.Exit ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("ENTER THE ELEMENT : ");
                    x = sc.nextInt();
                    h.add(x);
                    break;
                case 2:
                    System.out.print("Enter the element to remove :");
                    x = sc.nextInt();
                    h.remove(x);
                    break;
                case 3:
                    System.out.print("Enter the element to check:");
                    x = sc.nextInt();
                    if (h.contains(x)) {
                        System.out.println("It contains " + x);
                    } else {
                        System.out.println("It does not contains" + x);
                    }
                    break;
                case 4:
                    System.out.println("The hash set is : " + h);
                    break;
                case 5:
                    break;
                default:
                    System.out.println("Wrong Choice !!");
                    break;
            }
        } while (ch != 5);
        sc.close();
    }

    public static void stack() {
        Scanner sc = new Scanner(System.in);

        Stack<Integer> s = new Stack<Integer>();
        int ch, x;

        do {
            System.out.println("1.Push \n 2.Pop \n 3.Peek \n 4.isEmpty \n 5.Exit");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter element to be pushed");
                    x = sc.nextInt();
                    s.push(x);
                    break;

                case 2:
                    s.pop();
                    System.out.println("Element Popped");
                    break;

                case 3:
                    if (!s.isEmpty())
                        System.out.println("Top of stack : " + s.peek());
                    break;
                case 4:
                    if (s.isEmpty())
                        System.out.println("Stack is Empty");
                    else
                        System.out.println("Stack is not empty");
                    break;
                case 5:
                    break;

                default:
                    System.out.println("Wrong Choice !!");
                    break;
            }
        } while (ch != 5);
        sc.close();

    }

    public static void queue() {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<Integer>();
        int ch, x;

        do {
            System.out.println("1.Add \n 2.Remove \n 3.Peek \n 4.Size \n 5.Display \n 6.Exit");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter element to be added");
                    x = sc.nextInt();
                    q.add(x);
                    break;

                case 2:
                    q.remove();
                    System.out.println("Element Popped");
                    break;

                case 3:
                    if (!q.isEmpty())
                        System.out.println("Head  : " + q.peek());
                    break;
                case 4:
                    System.out.println("Size : " + q.size());
                    break;
                case 5:
                    System.out.println("Queue is : " + q);
                    break;

                case 6:
                    break;

                default:
                    System.out.println("Wrong Choice !!");
                    break;
            }
        } while (ch != 6);
        sc.close();

    }

    public static void deque() {
        Scanner sc = new Scanner(System.in);

        Deque<Integer> d = new LinkedList<Integer>();
        int ch, x;

        do {
            System.out.println(
                    "1.Add Front \n 2.Add Rear \n 3.Remove Front \n 4. Remove Rear \n 5.Display Front \n 6.Display Rear \n 7.Display Deque \n 8.Exit");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter element to be added");
                    x = sc.nextInt();
                    d.addFirst(x);
                    break;

                case 2:
                    System.out.println("Enter element to be added");
                    x = sc.nextInt();
                    d.addLast(x);
                    break;

                case 3:
                    d.removeFirst();
                    System.out.println("Element Deleted");
                    break;

                case 4:
                    d.removeLast();
                    System.out.println("Element Deleted");
                    break;

                case 5:
                    System.out.println("Front : " + d.peekFirst());
                    break;

                case 6:
                    System.out.println("Rear : " + d.peekLast());
                    break;

                case 7:
                    System.out.println("Deque is : " + d);
                    break;

                case 8:
                    break;

                default:
                    System.out.println("Wrong Choice !!");
                    break;
            }
        } while (ch != 8);
        sc.close();

    }

    public static void main(String[] args) {
        // stack();
        // LL();
        // Hash();
        // queue();
        deque();
    }
}