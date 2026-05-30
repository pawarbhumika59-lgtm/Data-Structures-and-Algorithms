#include<iostream>
using namespace std;
int main (){
     int n;
    cout << "Enter number of elements : " ;
    cin >> n;

    int array[n];
    cout << "Enter the elements one by one :-" << endl;
    for (int i=0 ; i<n ; i++){
        cout << "Enter element " << i+1 << " : ";
        cin >> array[i] ;
    }

    cout << "The list of elements is (unsorted) : ";
    for (int i=0 ; i<n ; i++){
        cout << array[i] << " ";
    }

    // Insertion Sort
    for (int i=1 ; i<n ; i++ ){
        int insert_index = i;
        int current_value = array[i];
        int j = i-1 ;

        while (j>=0 && array[j] > current_value ){
            array[j+1] = array[j];
            insert_index = j;
            j--;
        }
        array[insert_index] = current_value;
    }

    cout << "\nThe list after insertion sort is : ";
    for (int i=0 ; i<n ; i++){
        cout << array[i] << " ";
    }

    return 0;
}