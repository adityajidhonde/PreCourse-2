#include <bits/stdc++.h> 
using namespace std;  
   
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    //Your Code here 
    int temp=*a;*a=*b;*b=temp;
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    //Your Code here 
    int t=high-1,it=high-1,x=arr[high];
    while(it>=low && t>=low){
        if(arr[it]>x){
            swap(&arr[it],&arr[t]);t--;
        }
        it--;
    }
    if(t==high){
        return t;
    }
    swap(arr[high],arr[t+1]);
    return (t+1);
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    //Your Code here 
    if(low>high){
        return;
    }
    int p=partition(arr,low,high);
    // printArray(arr,6);
    // cout<<p<<'\n';
    quickSort(arr,low,p-1);
    quickSort(arr,p+1,high);
}  
  
/* Function to print an array */
 void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}
  
// Driver Code 
int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  