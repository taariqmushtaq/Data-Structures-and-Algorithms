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
        return (toss == nullptr);
    }

    void push(string data) // Change the parameter type to string
    {
        node *newptr = new node(data); // Allocate memory for the new node
        newptr->nxtptr = toss;
        toss = newptr;
    }

    string pop()
    {
        if (isempty())
        {
            cout << "stack is empty " << endl;
            return " ";
        }
        
        node *temp = toss;
        toss = temp->nxtptr;
        temp->nxtptr = nullptr;

        string poppedData = temp->data; // Save the data before deleting the node
        delete temp; // Free the memory

        return poppedData;
    }

    string peek() // Change the function name to peek
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return " ";
        }
        return toss->data;
    }

    int sizelist()
    {
        int count = 0;
        node *rptr = toss;

        while (rptr != nullptr)
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
            node *rptr = toss;

            while (rptr != nullptr)
            {
                cout << rptr->data << " | ";
                rptr = rptr->nxtptr;
            }
            cout << endl;
        }
    }

    int evaluate(string exp)
    {
        int result = 0;
        int num1, num2;
        string temp;

        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] == ' ')
            {
                continue;
            }
            else if (isdigit(exp[i]))
            {
                temp = exp[i];
                push(temp);
            }
            else
            {
                num1 = stoi(pop());
                num2 = stoi(pop());

                switch (exp[i])
                {
                case '+':
                    result = num2 + num1;
                    break;
                case '-':
                    result = num2 - num1;
                    break;
                case '*':
                    result = num2 * num1;
                    break;
                case '/':
                    result = num2 / num1;
                    break;
                }

                temp = to_string(result);
                push(temp);
            }
        }
        return result;
    }
};

int main()
{
    stack s;
    string exp;

    cout << "ENTER THE EXPRESSION" << endl;
    getline(cin, exp); // Use getline to allow spaces in the expression
    int res = s.evaluate(exp);
    cout << "RESULT: " << res << endl;

    return 0;
}
