#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    int temp[100];   

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int x = low; x <= high; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[100], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nMenu:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Merge Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            insertionSort(arr, n);
            cout << "\nSorted using Insertion Sort:\n";
            break;

        case 2:
            mergeSort(arr, 0, n - 1);
            cout << "\nSorted using Merge Sort:\n";
            break;

        default:
            cout << "Invalid Choice!";
            return 0;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}