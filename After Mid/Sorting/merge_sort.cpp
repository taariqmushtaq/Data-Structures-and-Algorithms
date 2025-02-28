#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
   int n1 = mid - left + 1;
   int n2 = right - mid;

   // Create temporary arrays
   int L[n1], R[n2];

   // Copy data to temporary arrays L[] and R[]
   for (int i = 0; i < n1; i++)
      L[i] = arr[left + i];
   for (int j = 0; j < n2; j++)
      R[j] = arr[mid + 1 + j];

   // Merge the temporary arrays back into arr[left..right]
   int i = 0, j = 0, k = left;
   while (i < n1 && j < n2)
   {
      if (L[i] <= R[j])
      {
         arr[k] = L[i];
         i++;
      }
      else
      {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   // Copy the remaining elements of L[], if there are any
   while (i < n1)
   {
      arr[k] = L[i];
      i++;
      k++;
   }

   // Copy the remaining elements of R[], if there are any
   while (j < n2)
   {
      arr[k] = R[j];
      j++;
      k++;
   }
}
// #2: Function to implement merge sort algorithm
void mergeSort(int arr[], int left, int right)
{
   if (left < right)
   {
      // Same as (left + right) / 2, but avoids overflow for large left and right
      int mid = left + (right - left) / 2;

      // Sort first and second halves
      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);

      // Merge the sorted halves
      merge(arr, left, mid, right);
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

    mergeSort(array, 0, size - 1);

    cout << "SORTED ARRAY:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}