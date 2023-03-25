#include <iostream>
using namespace std;

class queue
{
private:
    
    int *arr;
    int size;
    int front;
    int rear;

public:

    queue(int size)  // Constructor
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int val)
    {
        // overflow condition
        if(rear == size)
        {
            cout<<"Queue overflowed"<<endl;
            return;
        }

        else
        {
            arr[rear] = val;
            rear++;
        }
    }

    void dequeue()
    {
        // Underflow condition
        if(front == rear)
        {
            cout<<"Queue underflowed"<<endl;
            return;
        }

        else
        {
            front++;
            if(front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int qSize()
    {
        return rear - front;
    }

    int qfront()
    {
        if(rear == front)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if(rear == front)
            return true;
        else
            return false;
    }
};

int main()
{
    queue q(5);

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    q.dequeue();
    q.dequeue();

    cout<<q.qfront()<<endl;
    cout<<q.qSize()<<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout<<q.isEmpty()<<endl;

    return 0;
}