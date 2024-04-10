#include <iostream>
using namespace std;

const int tablesize = 10;

class hashnode
{
public:
    int arr[tablesize];
    hashnode()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = -1;
        }
    }

    void lprob(int key)
    {
        int index = 0;
        index = key % 10;

        if (arr[index] == -1)
        {
            arr[index] = key;
        }
        else
        {
            int i = 0;
            while (arr[index] != -1)
            {
                index = (key + i) % 10;
                i++;
            }
            arr[index] = key;
        }
    }

    void qprob(int key)
    {
        int index;
        index = key % tablesize;
        if (arr[index] == -1)
        {
            arr[index] = key;
        }
        else
        {
            int i = 0;
            while (arr[index] != -1)
            {
                index = (key + (i * i)) % tablesize;
                i++;
            }
            arr[index] = key;
        }
    }

    int sfolding(int key)
    {
        int sum = 0;
        int pre = 0;

        while (key != 0)
        {
            pre = key % tablesize;
            sum = sum + pre;
            key = key / tablesize;
        }

        return sum;
    }

    int msquare(int key)
    {
        int squared = key * key;
        int numDigits = 0;
        int temp = squared;

        while (temp > 0)
        {
            temp /= 10;
            numDigits++;
        }

        int middleDigits = (squared / 10);
        int hash = middleDigits % tablesize;

        return hash;
    }

    int extraction(int key)
    {
        int sum = 0;
        int temp = key;

        while (temp != 0)
        {
            sum += temp % 10;
            temp /= 10;
        }

        return sum % tablesize;
    }

    int redex(int key, int step)
    {
        int sum = 0;
        int temp = key;
        int count = 0;

        while (temp != 0)
        {
            if (count % step == 0)
            {
                sum += temp % 10;
            }
            temp /= 10;
            count++;
        }

        return sum % tablesize;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    hashnode l;
    int n, ch;

    cout << "Select a Hashing Method:" << endl;
    cout << "1. Linear Probing" << endl;
    cout << "2. Quadratic Probing" << endl;
    cout << "3. Shift Folding" << endl;
    cout << "4. Mid Square" << endl;
    cout << "5. Extraction" << endl;
    cout << "6. Redex Method" << endl;
    cin >> ch;

    if (ch >= 1 && ch <= 6)
    {
        cout << "Enter the values:" << endl;
        for (int i = 0; i < 10; i++)
        {
            cin >> n;
            if (ch == 1)
                l.lprob(n);
            else if (ch == 2)
                l.qprob(n);
            else if (ch == 3)
                l.lprob(l.sfolding(n));
            else if (ch == 4)
                l.lprob(l.msquare(n));
            else if (ch == 5)
                l.lprob(l.extraction(n));
            else if (ch == 6)
            {
                int step;
                cout << "Enter the step value for Redex Method: ";
                cin >> step;
                l.lprob(l.redex(n, step));
            }
        }
        cout << endl;
        cout << "HASH TABLE:" << endl;
        l.display();
    }
    else
    {
        cout << "Invalid choice. Please select a valid method (1-6)." << endl;
    }

    return 0;
}
