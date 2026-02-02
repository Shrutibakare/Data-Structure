#include <iostream>
using namespace std;

int main() {
    int n, key, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nEnter your choice: ";
    cin >> choice;

    cout << "Enter element to search: ";
    cin >> key;

    switch (choice) {

        case 1:  
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Element found at index " << i;
                    return 0;
                }
                
            }
           
        case 2:  
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] == key) {
                    cout << "Element found at index " << mid;
                    return 0;
                } else if (arr[mid] < key)
                    low = mid + 1;
                else
                    high = mid - 1;

            }
            
        
    }

    return 0;
}
