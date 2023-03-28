#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pv = partition(arr, low, high);
        
        quickSort(arr, low, pv - 1);
        quickSort(arr, pv + 1, high);
    }
}

void quickSortIterative(int arr[], int low, int high)
{
    int stack[high - low + 1];
  
    int top = -1;
  
    stack[++top] = low;
    stack[++top] = high;
  
    while (top >= 0) {
    
        high = stack[top--];
        low = stack[top--];
  
        int pv = partition(arr, low, high);
  
        
        if (pv - 1 > low) {
            stack[++top] = low;
            stack[++top] = pv - 1;
        }
  
    
        if (pv + 1 < high) {
            stack[++top] = pv + 1;
            stack[++top] = high;
        }
    }
}

int main() {
    srand(time(nullptr)); // Seed the random number generator with the current time
    
    // Generate five random arrays with lengths in the range of [3, 20]
    for (int i = 0; i < 9; i++) {
        int length = rand() % 18 + 3; // Randomly choose a length between 3 and 20
        int* arr = new int[length]; // Allocate memory for the array
        
        // Fill the array with random numbers between 0 and 99
        for (int j = 0; j < length; j++) {
            arr[j] = rand() % 100;
        }
        
        int QuickArr[length];
    
        // Copy the source array to the destination array
        for (int i = 0; i < length; i++) {
            QuickArr[i] = arr[i];
        }
        //cout << "Original array: ";
        //for (int i = 0; i < length; i++){
          //  cout << arr[i] << " ";
        //}
        //cout << endl;

        
        auto start_timei = high_resolution_clock::now();
        quickSort(QuickArr,0,length-1);
        auto end_timei = high_resolution_clock::now();
        auto durationi = duration_cast<nanoseconds>(end_timei - start_timei);
        
        cout<<"Total elements in array: "<<length<<endl;
        cout << "Time taken to sort the array in recursive quick sort: " << durationi.count()/1e3 << " microseconds" << endl;
        //cout << "Sorted array: ";
        //for (int i = 0; i < length; i++){
            //cout << QuickArr[i] << " ";
        //}
        //cout<< endl;
        
        //cout << "Original array: ";
        //for (int i = 0; i < length; i++){
            //cout << arr[i] << " ";
        //}
        //cout << endl;
        
        auto start_timej = high_resolution_clock::now();
        quickSortIterative(arr,0,length-1);
        auto end_timej = high_resolution_clock::now();
        auto durationj = duration_cast<nanoseconds>(end_timej - start_timej);
        
        //cout<<"Total elements in array: "<<length<<endl;
        cout << "Time taken to sort the array in iterative quick sort: " << durationj.count()/1e3 << " microseconds" << endl;
        //cout << "Sorted array: ";
        //for (int i = 0; i < length; i++){
            //cout << arr[i] << " ";
        //}
        //cout<< endl;
    }

    return 0;
}