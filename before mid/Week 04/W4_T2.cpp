#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string data;
    node *nxtptr;

    node()
    {
        data = " ";
        nxtptr = nullptr;
    }
    node(string data) 
    {
        this->data = data;
        nxtptr = nullptr;
    }
};

class stack
{
public:
    node *toss;

    stack()
    {
        toss = nullptr;
    }

    bool isempty()
    {
        return (toss == nullptr); // Simplify the isempty() function
    }

    void push(node *newptr)
    {
        newptr->nxtptr = toss;
        toss = newptr;
    }

    string pop()
    {
        if (isempty())
        {
            cout << "stack is empty " << endl;
            return " "; // Return a default value in case of an error
        }
        
        node *temp = toss;
        toss = temp->nxtptr;
        temp->nxtptr = nullptr; // Use '=' instead of '=='

        return temp->data;
    }

    string peak()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return " "; // Return a default value in case of an error
        }
        return toss->data;
    }

    int sizelist()
    {
        int count = 0;
        node *rptr = toss;

        while (rptr != nullptr) // Changed the condition to properly count the elements
        {
            rptr = rptr->nxtptr;
            count++;
        }
        return count;
    }

    void display()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            node *rptr;
            rptr = toss;

            while (rptr != nullptr)
            {
                cout << rptr->data << " |"
                     << " ";
                rptr = rptr->nxtptr;
            }
            cout << endl;
        }
    }

    bool isbal(string exp)
    {
        bool check = true;

        for (int i = 0; i < exp.length(); i++) // Use string length and a for loop
        {
            if (exp[i] == '{' || exp[i] == '(')
            {
                string val;
                val = exp[i];
                push(new node(val));
            }
            else if (exp[i] == '}' || exp[i] == ')')
            {
                string val;
                val = exp[i];
                if (exp[i] == '}')
                {
                    if (isempty())
                    {
                        check = false;
                    }
                    else if (peak() == "{")
                    {
                        pop();
                    }
                    else
                    {
                        check = false;
                    }
                }
                else if (exp[i] == ')')
                {
                    if(isempty())
                    {
                        check = false;
                    }
                    else if(peak() == "(")
                    {
                        pop();
                    }
                    else
                    {
                        check = false;
                    }
                }

                if (!check) // You can use !check instead of check == false
                {
                    return false;
                }
            }
        }
        return isempty(); // Return true if the stack is empty, false otherwise
    }
};

int main()
{
    stack s;

    string exp;

    cout << "ENTER EXP" << endl;
    cin >> exp;
    if (s.isbal(exp))
    {
        if (s.isempty())
        {
            cout << "CORRECT" << endl;
        }
        else
        {
            cout << "WRONG" << endl;
        }
    }
    else
    {
        cout << "WRONG" << endl;
    }

    return 0;
}
