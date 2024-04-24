#include<iostream>
#include<bits/stdc++.h>
#include<omp.h>
#include<stack>
#include<vector>

using namespace std;

void dfs(int start, int* arr, int n, int visited[]){

    #pragma omp for parallel ordered
    for(int i = 0; i < n; i++){
        #pragma omp ordered
        if((*(arr + (start * n) + i) == 1) &&(!visited[i])){
            visited[i] = 1;
            cout<<i<<" ";
            dfs(i, (int*) arr, n, visited);
        }
    }

}


int main() {

    int n;
    cout<<"V: ";
    cin>>n;

    int arr[n][n] = {0};

    int edges;
    cout<<"E: ";
    cin>>edges;

    for(int k = 0; k <edges; k++){
        int a, b;
        cin>>a>>b;
         arr[a][b] = 1;
         arr[a][b] = 1;
    }

     int visited[n] = {0};


cout<<"Enter the start vertex: ";
    int start;
    cin>>start;

    clock_t strt = clock();
    
    cout<<start<<" ";
    visited[start] = 1;
	dfs(start, (int *)arr, n, visited);
    
    clock_t stop = clock();

    cout<<"\nTime required : "<<(double)(stop-strt)<<" ms"<<endl;


    return 0;
}