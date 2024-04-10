#include <iostream>
#include <string>
using namespace std;

class stack
{
public:
    int *arr;
    int size;
    int top;

    stack()
    {
        arr = new int[10];

        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
        size = -1;
    }

    bool isempty()
    {
        if (size == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isfull()
    {
        if (size == 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int SIZE()
    {
        return size;
    }

    void push(int val)
    {
        if(isempty())
        {
            arr[++size] = val;
        }
        else if(!isfull())
        {
            arr[++size] = val;
        }
    }

    int pop()
    {
        if(!isempty())
        {
           return  arr[size--];
        }
    }

    void display()
    {

        while(!isempty())
        {
            cout << arr[size] <<" ";
            size--;
        }
        cout<<endl;
    }
};

int main()
{
    stack s;
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(9);

    s.display();

    return 0;
}
