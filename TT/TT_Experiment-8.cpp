#include <iostream>
#include <vector>

using namespace std;

void countingSort(int arr[], int n, int k) {
    int count[k + 1] = {0};
    int output[n];
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 1, 6, 3, 7, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    countingSort(arr, n, 8);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
