#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements:\n";
    int* ptr = arr;
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);
    }

    bool ascending = true, descending = true;

    for (int i = 0; i < n - 1; i++) {
        if (*(ptr + i) > *(ptr + i + 1)) {
            ascending = false;
        }
        if (*(ptr + i) < *(ptr + i + 1)) {
            descending = false;
        }
    }

    if (ascending) {
        cout << "Array is in ascending order.\n";
    } 
    else if (descending) {
        cout << "Array is in descending order.\n";
    } 
    else {
        cout << "Array is unordered.\n";
    }

    delete[] arr;

    return 0;
}
