#include <iostream>
#include <string>
using namespace std;

// Class to built an array based queue
class Q
{
public:
    int front;
    int rear;
    int size = 5;
    string *s;

    Q()
    {
        front = -1;
        rear = -1;
        s = new string[size];
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void enqueue(string data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }

        {
            s[++rear] = data;
        }
    }

    string dequeue()
    {
        string temp;

        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return " ";
        }
        else
        {
            temp = s[front];
            
            s[front] = -1;
            front++;
            return temp;
        }
    }

    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << i << endl;
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Q q;

    cout << " ENQUEUING THE ELEMENTS" << endl;
    q.enqueue("A");
    q.enqueue("B");
    q.enqueue("C");
    q.enqueue("D");
    q.enqueue("E");
    q.display();
    cout << endl;

    cout << "NOW DEQUEUING ELEMENTS" << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();

    return 0;
}
