#include <iostream>
using namespace std;

class Drop_off_stack
{
private:
    int *array;
    int itop;
    int ibottom;
    int entry_count;
    int array_capacity;

public:
    // Constructors
    Drop_off_stack(int n = 10) : itop(-1), ibottom(0), entry_count(0), array_capacity(n)
    {
        array = new int[n];
    }

    // Destructor
    ~Drop_off_stack()
    {
        delete[] array;
    }

    // Copy Constructor
    Drop_off_stack(const Drop_off_stack &other) : array(new int[other.array_capacity]), itop(other.itop), ibottom(other.ibottom), entry_count(other.entry_count), array_capacity(other.array_capacity)
    {
        // Copy elements from other array to this array
        for (int i = 0; i < array_capacity; ++i)
        {
            array[i] = other.array[i];
        }
    }

    // Accessors
    int top() const
    {
        if (empty())
        {
            cout << "Error: Stack is empty" << endl;
            exit(1);
        }
        return array[itop];
    }

    int size() const
    {
        return entry_count;
    }

    bool empty() const
    {
        return entry_count == 0;
    }

    // Mutators
    void swap(Drop_off_stack &other)
    {
        std::swap(array, other.array);
        std::swap(itop, other.itop);
        std::swap(ibottom, other.ibottom);
        std::swap(entry_count, other.entry_count);
        std::swap(array_capacity, other.array_capacity);
    }

    Drop_off_stack &operator=(Drop_off_stack other)
    {
        swap(other);
        return *this;
    }

    void push(const int &element)
    {
        if (entry_count == array_capacity)
        {
            // Stack is full, remove the element at the bottom
            ibottom = (ibottom + 1) % array_capacity;
            itop = (itop + 1) % array_capacity;
        }
        else
        {
            itop = (itop + 1) % array_capacity;
            entry_count++;
        }
        array[itop] = element;
        bsort(array);
    }

    void bsort(int arr[])
    {
        int i, j, temp;
        for (i = 0; i < entry_count; i++)
        {
            for (j = 0; j < entry_count - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    int pop()
    {
        if (empty())
        {
            cout << "Error: Stack is empty" << endl;
            exit(1);
        }
        int poppedElement = array[itop];
        itop = (itop - 1 + array_capacity) % array_capacity;
        entry_count--;
        return poppedElement;
    }

    void clear()
    {
        itop = -1;
        ibottom = 0;
        entry_count = 0;
    }

    // Friend function for cout
    friend ostream &operator<<(ostream &out, const Drop_off_stack &stack)
    {
        for (int i = 0; i < stack.entry_count; ++i)
        {
            out << stack.array[(stack.ibottom + i) % stack.array_capacity] << " ";
        }
        return out;
    }
};

int main()
{
    Drop_off_stack stack(5);
    int choice;
    int value;
    int x;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Push value" << endl;
        cout << "2. Pop value" << endl;
        cout << "3. Show stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "How many values you want to push" << endl;
            cin >> x;
            if(x>5)
            {
                cout<<"Error: Stack Size is 5"<<endl;
                break;
            }
            for (int i = 0; i < x; i++)
            {
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
            }
            cout << "Stack after push: " << stack << endl;
            break;

        case 2:
            if (!stack.empty())
            {
                stack.pop();
                cout << "Stack after pop: " << stack << endl;
            }
            else
            {
                cout << "Error: Stack is empty. Cannot pop." << endl;
            }
            break;

        case 3:
            cout << "Stack: " << stack << endl;
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 4);

    return 0;
}
