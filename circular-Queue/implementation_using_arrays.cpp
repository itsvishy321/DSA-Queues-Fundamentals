#include <iostream>
using namespace std;

class circularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // constructor
    circularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        // overflow condition
        if((rear+1)%size == front)
        {
            cout<<"Queue overflow"<<endl;
            return;
        }  

        else if(front == -1)
        {
            front  = rear = 0;
            arr[rear] = x;
        }

        else
        {
            rear = (rear+1) % size;
            arr[rear] = x;
        }
    }

    void dequeue()
    {
        // underflow condition
        if(front == -1)
        {
            cout<<"Queue underflow"<<endl;
            return;
        }

        else if(front == rear)
        {
            front = rear = -1;
        }

        else
        {
            front = (front + 1) % size;
        }
    }

    void display()
    {

        int i=front;
        do{
            cout<<arr[i]<<" ";
            i = (i+1)%size;
        }while(i != (rear+1)%size);

        cout<<endl;
    }

};

int main()
{
    int size;
    cin>>size;
    circularQueue q(size);

    int i;
    while(true)
    {
        cout<<"1 push"<<endl;
        cout<<"2 pop"<<endl;
        cin>>i;

        switch (i)
        {
        case 1:
            int x;
            cin>>x;
            q.enqueue(x);
            break;
        
        case 2:
            q.dequeue();
            break;
        
        default:
            break;
        
        }

        q.display();
    }
    return 0;
}