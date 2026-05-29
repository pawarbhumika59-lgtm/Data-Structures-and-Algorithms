#include<iostream>
using namespace std;
int main()
{
int n;
cout << "Enter number of elements :";
cin >> n;
int array[n];
for (int i=0; i<n; i++){
    cout << "Enter element " << i+1 << " : ";
    cin >> array[i];
}
cout << '\n' << "The Element list is (Unsorted) : ";
for(int i=0 ; i<n ; i++){
    cout << array[i] << " ";
}

//Bubble sort
for(int i=0; i<n-1 ; i++){
    for (int j=0; j<n-i-1; j++){
        if (array[j]>array[j+1]){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
}

cout <<"\nThe Elements after bubble sort are : ";
for (int i= 0; i<n; i++){
    cout << array[i] <<" ";
}
return 0;

}