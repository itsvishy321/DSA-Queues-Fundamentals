#include <iostream>
using namespace std;

// Node structure for linked list
class Node
{
public:
    int data;
    Node* next;

    // constructor
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// class for queue using Nodes in linked list
class queue
{
private:
    Node* front;
    Node* rear;

public:
    // constructor
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val)
    {
        Node* temp = new Node(val);

        if (temp == NULL)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        else if (front == NULL)
        {
            front = temp;
            rear = temp;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }

    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        else
        {
            front = front->next;
            if(front == NULL)
                rear = NULL;
        }
    }

    int qfront()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        else
            return front->data;
    }

    int qSize()
    {
        Node* temp = front;
        int cnt = 0;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }

};


int main()
{
    queue q;

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    q.dequeue();
    q.dequeue();

    cout << q.qfront() << endl;
    cout << q.qSize() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();    
    q.dequeue();

    cout << q.isEmpty() << endl;
    return 0;
}