#include<iostream>
#include<omp.h>
#include<time.h>

using namespace std;

void bubbleSort(int a[], int n)
 {  
   int i, j, temp;  
   for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(a[j] < a[i])    
            {    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }     
 }  

int main(){

    int arr[] =  {23, 42, 12, 32, 19, 89};
    int n = sizeof(arr)/sizeof(arr[0]);

    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    for(int z = 0; z < n; z++){
        cout<<arr[z]<<" ";
    }
    cout<<"Time: "<<(double)(end - start);
    

    return 0;
}