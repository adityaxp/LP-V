#include<iostream>
#include<omp.h>
#include<time.h>


using namespace std;

int main(){

    int arr1[10][10], arr2[10][10], ans[10][10], row, col, i ,j;
    cin>>row>>col;

    #pragma omp parallel for
    for(i = 0; i <row ; i++){
        #pragma omp parallel for
         for(j = 0; j <col ; j++){
             arr1[i][j] = rand()%10;
        }   
    }

    #pragma omp parallel for
    for(i = 0; i <row ; i++){
        #pragma omp parallel for
         for(j = 0; j <col ; j++){
             cout<<arr1[i][j]<<" ";
        }   
        cout<<endl;
    }

    #pragma omp parallel for
    for(i = 0; i <row ; i++){
        #pragma omp parallel for
         for(j = 0; j <col ; j++){
             arr2[i][j] = rand()%10;
        }   
    }

    

    #pragma omp parallel for
    for(i = 0; i <row ; i++){
        #pragma omp parallel for
         for(j = 0; j <col ; j++){
             cout<<ans[i][j]<<" ";
        }   
        cout<<endl;
    }

    #pragma omp parallel for
     for(i = 0; i <row ; i++){
        #pragma omp parallel for
         for(j = 0; j <col ; j++){
             ans[i][j]= arr1[i][j] * arr2[i][j];
        }   
    }
    #pragma omp parallel for
    for(i = 0; i <row ; i++){
        #pragma omp parallel for
         for(j = 0; j <col ; j++){
             cout<<ans[i][j]<<" ";
        }   
        cout<<endl;
    }


    return 0;
}