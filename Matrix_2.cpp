#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2, choice;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;

    int A[10][10], B[10][10], C[10][10];

    cout << "\nEnter elements of Matrix A:\n";
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nEnter elements of Matrix B:\n";
    for(int i = 0; i < r2; i++) {
        for(int j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    do {
        cout << "\n----- MATRIX OPERATIONS MENU -----\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if(r1 == r2 && c1 == c2) {
                    cout << "\nMatrix Addition:\n";
                    for(int i = 0; i < r1; i++) {
                        for(int j = 0; j < c1; j++) {
                            C[i][j] = A[i][j] + B[i][j];
                            cout << C[i][j] << " ";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Addition not possible!\n";
                }
                break;

            case 2:
                if(r1 == r2 && c1 == c2) {
                    cout << "\nMatrix Subtraction:\n";
                    for(int i = 0; i < r1; i++) {
                        for(int j = 0; j < c1; j++) {
                            C[i][j] = A[i][j] - B[i][j];
                            cout << C[i][j] << " ";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Subtraction not possible!\n";
                }
                break;

            case 3:
                if(c1 == r2) {
                    cout << "\nMatrix Multiplication:\n";
                    for(int i = 0; i < r1; i++) {
                        for(int j = 0; j < c2; j++) {
                            C[i][j] = 0;
                            for(int k = 0; k < c1; k++) {
                                C[i][j] += A[i][k] * B[k][j];
                            }
                            cout << C[i][j] << " ";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Multiplication not possible!\n";
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
