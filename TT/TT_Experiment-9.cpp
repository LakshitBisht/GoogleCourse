#include <iostream>
#include <vector>

using namespace std;

// A helper function to partition the array
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // Select the last element as the pivot
    int i = low - 1;  // Index of the smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;  // Increment the index of the smaller element
            swap(arr[i], arr[j]);  // Swap the current element with the smaller element
        }
    }
    swap(arr[i + 1], arr[high]);  // Swap the pivot with the element at the next index of the smaller element
    return i + 1;  // Return the index of the pivot
}

// The main Quick Sort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition the array
        quickSort(arr, low, pi - 1);  // Recursively sort the left subarray
        quickSort(arr, pi + 1, high);  // Recursively sort the right subarray
    }
}

// A helper function to print the array
void printArray(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// The main function to test the Quick Sort algorithm
int main() {
    vector<int> arr = {85, 92, 81, 79, 91, 75};
    cout << "Marks Obtained by different students: ";
    printArray(arr);
    quickSort(arr, 0, arr.size() - 1);
    cout << "Sorted Marks of students: ";
    printArray(arr);
    return 0;
}
