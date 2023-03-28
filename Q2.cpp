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
double median(int arr[],int l){
    if (l%2==1){
        return arr[(l-1)/2];
    }
    else{
        return (arr[(l/2)] + arr[(l/2)-1])/2.0;
    }
}

int main() {
  srand(time(nullptr)); // Seed the random number generator with the current time
  int length = 10;
  int* arr = new int[length];
  for (int j = 0; j < length; j++) {
    arr[j] = rand() % 100;
    }
    
  cout << "Original array: ";
  for (int i = 0; i < length; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  
  int *ar = new int [length];
  for (int i = 0; i<length; i++){
    ar[i] = arr[i];
    quickSort(ar,0,i);
    cout << "[";
    for (int j=0;j<i+1;j++){
      cout << ar[j] << " ";
    }
    cout << "] : median: ";
    cout<< median(ar,i+1);
    cout << endl;
    
  }
  
    
      
  return 0;
}