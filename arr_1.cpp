#include <iostream>
using namespace std;

void display(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[100], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Update\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting program...\n";
            break;
        }

        switch (choice) {
            case 1: {
                int pos, val;
                cout << "Enter position (0-based): ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> val;

                if (pos < 0 || pos > n) {
                    cout << "Invalid position!\n";
                } else {
                    for (int i = n; i > pos; i--)
                        arr[i] = arr[i - 1];
                    arr[pos] = val;
                    n++;
                }
                break;
            }

            case 2: {
                int pos;
                cout << "Enter position to delete (0-based): ";
                cin >> pos;

                if (pos < 0 || pos >= n) {
                    cout << "Invalid position!\n";
                } else {
                    for (int i = pos; i < n - 1; i++)
                        arr[i] = arr[i + 1];
                    n--;
                }
                break;
            }

            case 3: {
                int key, found = 0;
                cout << "Enter element to search: ";
                cin >> key;

                for (int i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        cout << "Element found at index " << i << endl;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "Element not found!\n";
                break;
            }

            case 4: {
                int pos, val;
                cout << "Enter position to update (0-based): ";
                cin >> pos;

                if (pos < 0 || pos >= n) {
                    cout << "Invalid position!\n";
                } else {
                    cout << "Enter new value: ";
                    cin >> val;
                    arr[pos] = val;
                }
                break;
            }

            case 5:
                break;

            default:
                cout << "Invalid choice!\n";
        }

        display(arr, n);
    }

    return 0;
}

