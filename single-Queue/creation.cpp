#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    // Inserting values
    q.push(5);
    q.push(2);
    q.push(4);
    q.push(1);

    // finding size 
    cout << "size of queue is " << q.size() << endl;

    // Deleting elements
    q.pop();
    q.pop();

    // finding front element
    cout<<"Front element of queue is "<<q.front()<<endl;

    q.pop();
    q.pop();

    if(q.empty())
        cout<<"Queue is Empty"<<endl;
    else
        cout<<"Queue is NOT Empty"<<endl;
    

    return 0;
}