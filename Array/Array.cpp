//This code includes all the concepts of array
#include <iostream>
using namespace std;

const int MAX = 100; 
/*WHY??? 
Because we need to define a maximum size for the array,
as C++ does not support dynamic arrays without using pointers or STL. 
This allows us to create a fixed-size array that can hold up to MAX elements.*/

void display(int arr[], int n)
{
    if(n == 0)
    {
        cout << "\nArray is Empty!\n";
        return;
    }

    cout << "\nArray Elements: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertBeginning(int arr[], int &n, int value)
{
    for(int i = n; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = value;
    n++;
}
//Why reference? Because we want to modify the | actual size | of the array in the main function.

void insertEnd(int arr[], int &n, int value)
{
    arr[n] = value;
    n++;
}

void insertPosition(int arr[], int &n, int pos, int value)
{
    if(pos < 1 || pos > n + 1)
    {
        cout << "Invalid Position!\n";
        return;
    }

    for(int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = value;
    n++;
}

void deleteBeginning(int arr[], int &n)
{
    if(n == 0)
    {
        cout << "Array Empty!\n";
        return;
    }

    for(int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
}

void deleteEnd(int &n)
{
    if(n == 0)
    {
        cout << "Array Empty!\n";
        return;
    }

    n--;
}

void deletePosition(int arr[], int &n, int pos)
{
    if(pos < 1 || pos > n)
    {
        cout << "Invalid Position!\n";
        return;
    }

    for(int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
}

void linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            cout << "Element Found at Position "
                 << i + 1 << endl;
            return;
        }
    }

    cout << "Element Not Found!\n";
}

void updateElement(int arr[], int n, int pos, int value)
{
    if(pos < 1 || pos > n)
    {
        cout << "Invalid Position!\n";
        return;
    }

    arr[pos - 1] = value;
}

void findMax(int arr[], int n)
{
    if(n == 0)
    {
        cout << "Array Empty!\n";
        return;
    }

    int max = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    cout << "Maximum Element = " << max << endl;
}

void findMin(int arr[], int n)
{
    if(n == 0)
    {
        cout << "Array Empty!\n";
        return;
    }

    int min = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }

    cout << "Minimum Element = " << min << endl;
}

void reverseArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while(start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    cout << "Array Sorted Successfully!\n";
}

int main()
{
    int arr[MAX];
    int n;

    cout << "Enter Number of Elements: ";
    cin >> n;

    cout << "Enter Elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int choice, value, pos, key;

    do
    {
        cout << "\n========== ARRAY MENU ==========\n";
        cout << "1. Display Array\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Position\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete from Position\n";
        cout << "8. Search Element\n";
        cout << "9. Update Element\n";
        cout << "10. Find Maximum\n";
        cout << "11. Find Minimum\n";
        cout << "12. Reverse Array\n";
        cout << "13. Bubble Sort\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                display(arr, n);
                break;

            case 2:
                cout << "Enter Value: ";
                cin >> value;
                insertBeginning(arr, n, value);
                break;

            case 3:
                cout << "Enter Value: ";
                cin >> value;
                insertEnd(arr, n, value);
                break;

            case 4:
                cout << "Enter Position: ";
                cin >> pos;
                cout << "Enter Value: ";
                cin >> value;
                insertPosition(arr, n, pos, value);
                break;

            case 5:
                deleteBeginning(arr, n);
                break;

            case 6:
                deleteEnd(n);
                break;

            case 7:
                cout << "Enter Position: ";
                cin >> pos;
                deletePosition(arr, n, pos);
                break;

            case 8:
                cout << "Enter Element to Search: ";
                cin >> key;
                linearSearch(arr, n, key);
                break;

            case 9:
                cout << "Enter Position: ";
                cin >> pos;
                cout << "Enter New Value: ";
                cin >> value;
                updateElement(arr, n, pos, value);
                break;

            case 10:
                findMax(arr, n);
                break;

            case 11:
                findMin(arr, n);
                break;

            case 12:
                reverseArray(arr, n);
                break;

            case 13:
                bubbleSort(arr, n);
                break;

            case 0:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 0);

    return 0;
}