#include <iostream>
using namespace std;

#include <bits/stdc++.h> 
class Deque
{
public:
    int size;
    int *arr;
    int front;
    int rear;


    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
        bool pushFront(int x) {
        if ((rear + 1) % size == front)
            return false;
        else if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = size - 1;
        else
            front--;
        arr[front] = x;
        return true;
    }

    bool pushRear(int x) {
        if ((rear + 1) % size == front)
            return false;
        else if (front == -1) {
            front = rear = 0;
            arr[rear] = x;
        }
        else {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
        return true;
    }

    int popFront() {
        if (front == -1)
            return -1;
        else {
            int temp = arr[front];
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % size;
            return temp;
        }
    }

    int popRear() {
        if (front == -1)
            return -1;
        else {
            int temp = arr[rear];
            if (front == rear)
                front = rear = -1;
            else if (rear == 0)
                rear = size - 1;
            else
                rear--;
            return temp;
        }
    }

    int getFront() {
        if (front == -1)
            return -1;
        else
            return arr[front];
    }

    int getRear() {
        if (front == -1)
            return -1;
        else
            return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }
};

int main()
{
    return 0;
}