#include <iostream>
using namespace std;

// Function to swap two integers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    // Validate input
    if (n <= 0) {
        cout << "Invalid input. Number of elements must be greater than zero." << endl;
        return 1;
    }
    
    int arr[n];
    
    // Input array elements
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    // Sorting order choice
    char order;
    cout << "Enter 'A' for ascending order or 'D' for descending order: ";
    cin >> order;
    
    bool ascending;
    if (order == 'A' || order == 'a') {
        ascending = true;
    } else if (order == 'D' || order == 'd') {
        ascending = false;
    } else {
        cout << "Invalid sorting order choice. Please enter 'A' or 'D'." << endl;
        return 1;
    }
    
    // Perform bubble sort based on user choice
    bubbleSort(arr, n, ascending);
    
    // Display sorted array
    displayArray(arr, n);
    
    return 0;
}

