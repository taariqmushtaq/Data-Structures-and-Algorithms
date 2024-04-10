#include <iostream>
using namespace std;

// BUBBLE SORT
void bubbleSort(int arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      for (int j = 0; j < n - i - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            // Swap elements if they are in the wrong order
            swap(arr[j], arr[j + 1]);
         }
      }
   }
}

// Selection sort
void selectionSort(int arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      int minIndex = i;
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[minIndex])
         {
            // Update the minimum element index if a smaller element is found
            minIndex = j;
         }
      }

      // Swap the found minimum element with the element at index i
      int temp = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = temp;
   }
}

// Insertion sort
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

// MERGE SORT:

// #1: Function to merge two sub-arrays arr[left..mid] and arr[mid+1..right]
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

// Quick SORT
// #1: Function to partition the array and return the pivot index
int partition(int arr[], int low, int high)
{
   int pivot = arr[high];
   int i = low - 1;

   for (int j = low; j <= high - 1; j++)
   {
      if (arr[j] <= pivot)
      {
         i++;
         swap(arr[i], arr[j]);
      }
   }

   swap(arr[i + 1], arr[high]);
   return i + 1;
}
// #2: Function to implement quick sort
void quickSort(int arr[], int low, int high)
{
   if (low < high)
   {
      // Find the pivot index such that elements smaller than the pivot are on the left
      // and elements greater than the pivot are on the right
      int pivotIndex = partition(arr, low, high);

      // Recursively sort the sub-arrays
      quickSort(arr, low, pivotIndex - 1);
      quickSort(arr, pivotIndex + 1, high);
   }
}

int main()
{
   int arr[] = {64, 25, 12, 22, 11};
   int n = sizeof(arr) / sizeof(arr[0]);

   std::cout << "Original array: ";
   for (int i = 0; i < n; i++)
      std::cout << arr[i] << " ";
   std::cout << "\n";

   //bubbleSort(arr, n);
   //selectionSort(arr, n);
   // insertionSort(arr, n);
   // mergeSort(arr, 0, n - 1);
   quickSort(arr, 0, n - 1);

   std::cout << "Sorted array: ";
   for (int i = 0; i < n; i++)
      std::cout << arr[i] << " ";

   return 0;
}
