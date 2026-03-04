#include <iostream>
using namespace std;

#define SIZE 10

int main()
{
    int hashTable[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
    int key;
    cout << "Enter value to hash:" << endl;
    cin >> key;

    int index = key % SIZE;
    hashTable[index] = key;
    cout << "\nHash Index: " << index << endl;
    cout << "Value stored at index " << index << " = " << hashTable[index] << endl;
}