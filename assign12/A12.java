package mypackage;

import java.util.Scanner;

/**
 *
 * 
 */
abstract class MyStack {

    public final void pushTemplateMethod() {
        show();
        push();
        display();
    }

    abstract protected void push();

    abstract protected void display();

    protected void show() {
        System.out.println("Stack implementation");
    }
}

class IntStack extends MyStack {

    private int top;
    private int[] storage;

    IntStack(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Stack's capacity must be positive");
        }
        storage = new int[capacity];
        top = -1;
    }

    protected void push() {
        System.out.println("Enter the element:");
        Scanner sc = new Scanner(System.in);
        int value = sc.nextInt();
        try {
            if (top == storage.length - 1) {
                throw new Exception("Stack's underlying storage is overflow");
            }
            top++;
            storage[top] = value;
        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }

    }

    protected void display() {
        System.out.println("The stack contents are :");
        for (int i = top; i >= 0; i--) {
            System.out.print(storage[i] + " ");
        }
        System.out.println();
    }
}

public class A12 {

    public static void main(String[] args) {
        IntStack obj = new IntStack(5);
        obj.pushTemplateMethod();
        obj.pushTemplateMethod();
        obj.pushTemplateMethod();
        obj.pushTemplateMethod();
    }
}
