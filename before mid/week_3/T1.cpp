#include <iostream>
using namespace std;

// DOUBLY LINK LIST
class node
{
public:
    int data;
    node *next;
    node *pre;

    node(int val)
    {
        data = val;
        next = NULL;
        pre = NULL;
    }
};

class DLL
{
public:
    node *head;
    node *tail;

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insertion_at_head(int val)
    {
        node *temp = new node(val);

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->pre = temp;
            head = temp;
        }
    }

    void insertion_at_tail(int val)
    {
        node *temp = new node(val);

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *ptr = head;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->pre = ptr;
        }
    }

    void insert_any(int val, int pos)
    {
        node *temp = new node(val);

        if (head == NULL)
        {
            head = temp;
        }
        else if (pos == 1)
        {
            insertion_at_head(val);
        }
        else
        {
            node *ptr = head;

            for (int i = 1; i < pos - 1; i++)
            {
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }

    void del_at_tail()
    {
        node *ptr = head;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        node *temp = ptr->next;
        ptr->next = NULL;
        delete temp;
    }



    void del_any(int pos)
    {
        node *temp = head;

        if (pos == 1)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            node *ptr = head;

            for (int i = 1; i < pos - 1; i++)
            {
                ptr = ptr->next;
            }
            temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }
    }



    void display()
    {
        node *ptr = head;

        while (ptr != NULL)
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
        cout << endl;
    }
    
    //funtion to search by value
    void srch_bv(int val)
    {
        node *ptr = head;
        int flag = 0;

        
        while (ptr != NULL)
        {
            if (ptr->data == val)
            {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }


        if (flag == 1)
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
    

    }
};



int main()
{
    DLL o1;
    o1.insertion_at_head(1);
    o1.insertion_at_head(2);
    o1.insertion_at_head(3);
    o1.insertion_at_head(4);
    cout << "Insertion at head" << endl;
    o1.display();

    o1.insertion_at_tail(5);
    o1.insertion_at_tail(6);

    cout << "Insertion at tail" << endl;
    o1.display();

    cout << "Insertion at any position" << endl;
    o1.insert_any(7, 2);
    o1.insert_any(8, 5);
    o1.display();

    cout << "Insertion at any tail" << endl;
    o1.del_at_tail();
    o1.display();

    
    cout << "deletion at any position" << endl;
    o1.del_any(2);
    o1.del_any(5);
    o1.display();
}
