#include<iostream>
#include<omp.h>
#include<time.h>

using namespace std;


void quick(int arr[], int st, int end)
{
    if(st < end)
    {
        int pivot = arr[end];
        int i = st-1;
        int j = st;

        for(int var = j; var<end; var++)
        {
            if(arr[var] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[var];
                arr[var] = temp;
            }
        }

        // swap i+1 and end
        int temp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = temp;

        i++;

        #pragma omp parallel sections
        {
            #pragma omp section
            quick(arr,st,i-1);

            #pragma omp section
            quick(arr,i+1,end);
        }
    
    }

}





int main(){

    int arr[] =  {23, 42, 12, 32, 19, 89};
    int n = sizeof(arr)/sizeof(arr[0]);

    clock_t start = clock();
    quick(arr, 0, n-1);
    clock_t end = clock();
    for(int z = 0; z < n; z++){
        cout<<arr[z]<<" ";
    }
    cout<<"Time: "<<(double)(end - start);
    

    return 0;
}