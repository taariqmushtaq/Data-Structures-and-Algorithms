#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    cout << "ENTER THE SIZE OF ARRAY" << endl;
    cin >> size;
    int array[size];

    cout << "ENTER THE VALUES" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    bubble_sort(array, size);

    cout << "SORTED ARRAY:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
