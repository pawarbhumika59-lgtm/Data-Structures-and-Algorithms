#include<iostream>
using namespace std;

//Counting sort
void countingSort(int array[], int n){

    //Finding maximum element 
    int max_value = array[0];
    for(int i=1 ; i<n ; i++){
        if(array[i] > max_value){
            max_value = array[i];
        }
    }

    //creating a count array
    int count[max_value+1];

    //initializing count array
    for (int i=0 ; i<=max_value ; i++){
        count[i]=0;
    }

    //store frequency of each element
    for (int i=0 ; i<n ; i++){
        count[array[i]]++;
    }

    //Reconstructing array
    int index = 0;

    for (int i=0 ; i<=max_value ; i++){
        while(count[i]>0){
            array[index]=i;
            index++;
            count[i]--;
        }
    }
}
int main(){
    int n;

    cout << "How many entries ???";
    cin >> n;

    int array[n];

    for (int i=0 ; i<n ; i++){
        cout << "Enter element " << i+1 <<" : ";
        cin >> array[i];
    }

    cout << "Unsorted array : " ;
    for (int i=0 ; i<n ; i++){
        cout << array[i] << " ";
    }

    countingSort(array , n);

    cout << "\nSorted array : ";
    for (int i=0 ; i<n ; i++){
        cout << array[i] << " ";
    }

    return 0;
}