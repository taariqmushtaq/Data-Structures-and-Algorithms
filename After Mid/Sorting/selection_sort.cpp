#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[i])
         {
            // Update the minimum element index if a smaller element is found
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

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

    selectionSort(array, size);

    cout << "SORTED ARRAY:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}