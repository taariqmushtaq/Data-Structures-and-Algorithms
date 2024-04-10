#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~node() {}
};

class SLL
{
public:
    node *head;
    SLL()
    {
        head = NULL;
    }
    ~SLL() {}

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

    void del_at_head(int pos)
    {
        node *temp = head;
        if (pos == 1)
        {
            head = head->next;
            delete temp;
        }
    }

    void delete_atany(int pos)
    {
        if (pos == 1)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        else
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
    }

    void del_at_tail()
    {
        node* ptr= head;

        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }

        node *temp = ptr->next;
        ptr->next = NULL;
        delete temp;
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
    }
};



int main()
{
    SLL o1;
    o1.insertion_at_head(5);
    o1.insertion_at_head(2);
    o1.insertion_at_head(6);
    o1.insertion_at_tail(8);
    o1.insert_any(9, 3);

   o1.delete_atany(2);
   o1.delete_atany(4);
    
    o1.insertion_at_head(7);
    o1.insertion_at_tail(4);
    o1.display();
}
