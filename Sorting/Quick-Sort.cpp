#include<iostream>
using namespace std;

//Quick sort functions
int partition(int array[] , int low , int high){
    int pivot = array[low];

    int p = low + 1;
    int q = high;

    while (true){
        while(p<=high && array[p]<pivot){
            p++;
        }

        while(q>=low && array[q]>pivot){
            q--;
        }

        if (p>=q){
            break;
        }
        swap(array[p] , array[q]);
    }
    swap(array[low] , array[q]);
    
    return q;
};

void quickSort(int array[] , int low, int high){
    if (low < high){
        int pivot_index = partition(array, low , high);

        quickSort(array, low , pivot_index - 1);
        quickSort(array , pivot_index + 1 , high );
    }
};

int main(){
    int n;
    cout << "How many elements ??? ";
    cin >> n;
    int array[n];

    cout << "Enter elements one by one :- " << endl;
    for (int i=0 ; i<n ; i++ ){
        cout <<"Enter element " << i+1 << " : ";
        cin >>array[i];
    }
    cout << "The Elements are (Unsorted) : ";
    for (int i=0 ; i<n ; i++ ){
        cout << array[i] << " " ;
    }
    
    quickSort(array, 0 , n-1);

    cout << "\nAfter Quick Sort : ";
    for (int i=0 ; i<n ; i++){
        cout << array[i] << " " ;
    }
    return 0;
}