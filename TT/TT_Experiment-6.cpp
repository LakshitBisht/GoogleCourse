#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int rollno1[] = {1, 2, 3, 4, 5};
    string name[] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
    int rollno2[] = {1, 3, 5, 7, 9};
    string course[] = {"BE", "BCA", "BSc", "BCom", "BA"};
    int rollno3[] = {1, 2, 3, 4, 5};
    float cgpa[] = {8.0, 7.5, 9.0, 8.5, 7.0};
    int Roll[4];

    int n1 = sizeof(rollno1) / sizeof(int);
    int n2 = sizeof(rollno2) / sizeof(int);
    int n3 = sizeof(rollno3) / sizeof(int);

    int i = 0, j = 0, k = 0, ind = 0;

    while (i < n1 && j < n2 && k < n3) {
        if (rollno1[i] == rollno2[j] && rollno2[j] == rollno3[k]) {
            Roll[ind] = rollno1[i];
            ind++;
            i++;
            j++;
            k++;
        } else if (rollno1[i] < rollno2[j]) {
            i++;
        } else if (rollno2[j] < rollno3[k]) {
            j++;
        } else {
            k++;
        }
    }
    cout << "Common Roll Nuumbers are :";
    for (int i = 0; i < ind; i++) {
        cout << Roll[i] << ", ";
    }

    return 0;
}