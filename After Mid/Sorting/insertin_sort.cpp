#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
   for (int i = 1; i < n; i++)
   {
      int key = arr[i];
      int j = i - 1;

      // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
      while (j >= 0 && arr[j] > key)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }

      arr[j + 1] = key;
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

    insertionSort(array, size);

    cout << "SORTED ARRAY:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}