package app;

import java.util.*;

abstract class Stack {

    public void show() {
        System.out.println("Stack Implementation");
    }

    abstract protected void push();

    abstract protected void display();

    public final void stackTemplateMethod() {
        show();
        push();
        display();
    }

}

class IntStack extends Stack {
    private int top;
    int storage[];

    IntStack(int size) {
        if (size <= 0)
            throw new IllegalArgumentException("Please enter a valid Stack size");

        top = -1;
        storage = new int[size];
    }

    protected void push() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the element to be inserted");
        int x = sc.nextInt();

        try {
            if (top == storage.length - 1)
                throw new Exception("Overflow !!");
        } catch (Exception e) {
            System.out.println("Exception : " + e.getMessage());
        }

        storage[++top] = x;

    }

    protected void display() {
        System.out.println("Contents of Stack are : ");

        for (int i = top; i >= 0; i--)
            System.out.print(storage[i] + "\t");

        System.out.println();
    }
}

class CharStack extends Stack {
    private int top;
    char storage[];

    CharStack(int size) {
        if (size <= 0)
            throw new IllegalArgumentException("Please enter a valid Stack size");

        top = -1;
        storage = new char[size];
    }

    protected void push() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the element to be inserted");
        char x = sc.next().charAt(0);

        try {
            if (top == storage.length - 1)
                throw new Exception("Stack's underlying storage is overflow");
        } catch (Exception e) {
            System.out.println("Exception : " + e.getMessage());
        }
        storage[++top] = x;

    }

    protected void display() {
        System.out.println("Contents of Stack are : ");

        for (int i = top; i >= 0; i--)
            System.out.print(storage[i] + "\t");

        System.out.println();
    }
}

class Demo {
    public static void main(String args[]) {
        System.out.println("Int Stack");
        IntStack s1 = new IntStack(5);

        s1.stackTemplateMethod();
        s1.stackTemplateMethod();

        //
        System.out.println("Char Stack");
        CharStack s2 = new CharStack(5);

        s2.stackTemplateMethod();
        s2.stackTemplateMethod();
    }
}