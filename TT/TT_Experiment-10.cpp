#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void printarray(vector<int> array) {
    for (int i: array)
        cout << i << " ";
    cout << endl;
}

void sortarray(vector<int> array) {
    stack<int> stack;
    for (int i: array)
        stack.push(i);
    for (int i = 0; i < array.size(); i++) {
        array[i] = stack.top();
        stack.pop();
    }
    printarray(array);
}

int main() {
    vector<int> array1 = {9, 7, 6, 5, 3, 2};
    vector<int> array2 = {92, 87, 76, 55, 43, 12};
    cout << "Array 1: ";
    printarray(array1);
    cout << "After Sorting: ";
    sortarray(array1);
    cout << "\nArray 2: ";
    printarray(array2);
    cout << "After Sorting: ";
    sortarray(array2);
    return 0;
}