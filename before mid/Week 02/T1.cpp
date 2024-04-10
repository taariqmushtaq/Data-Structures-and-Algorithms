#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class SLL
{
public:
    node *head;
    SLL()
    {
        head = NULL;
    }

    void insert(int val)
    {
        node *node1 = new node(val);
        if (head == NULL)
        {
            head = node1;
        }
    }

    void display()
    {
           cout<<head->data<<endl;
    }
};


int main()
{
    SLL o1;
    o1.insert(5);
    o1.display();
}

