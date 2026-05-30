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

    //Selection sort
    for (int i=0 ; i<n ; i++){
        int min_index = i;
        for (int j=i+1 ; j<n ; j++){
            if(array[j] < array[min_index]){
                min_index = j;
            }
        }

        int min_value = array[min_index];
        for (int k=min_index ; k>i ; k--){
            array[k] = array[k-1];
        }
        array[i] = min_value;
    }

    cout << "\nThe list after selection sort is : ";
    for (int i=0 ; i<n ; i++){
        cout << array[i] << " ";
    }
    return 0;
}