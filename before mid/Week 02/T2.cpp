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
        node *temp = new node(val);

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *str = head;
            while (str->next != NULL)
            {
                str = str->next;
            }
            str->next = temp;
        }
    }

    void display()
    {
        node *str = head;
        while (str != NULL)
        {
            cout << str->data << endl;
            str = str->next;
        }
    }
};

int main()
{
    SLL o1;
    o1.insert(5);
    o1.insert(8);
    o1.insert(23);
    o1.insert(6);
    o1.display();
}