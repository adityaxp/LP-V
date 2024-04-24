#include<iostream>
#include<queue>
#include<omp.h>
#include<time.h>
#include<bits/stdc++.h>

using namespace std;


queue<int> q;
void bfs(int start, int *arr, int n, int visited[]){
    #pragma omp parallel for ordered
    for(int i = 0; i < n; i++){
        #pragma omp ordered
        if((*(arr + (n  * start) + i) == 1) && (!visited[i])){
            cout<<i<<" ";
            q.push(i);
            visited[i] = 1;
        }
    }
    q.pop();
    if(!q.empty()){
        bfs(q.front(), (int*) arr, n, visited);
    }
}

int main(){

    int n;
    cout<<"Enter no. vertices: ";
    cin>>n;

    int arr[n][n] = {0}; 


    int edges;
    cout<<"Enter number of edges: ";
    cin>>edges;

    for(int j=0; j<edges; j++)
    {
        int a, b;
        cout<<"Enter two edges: "<<endl;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    int visit[n] = {0};

    cout<<"Enter the start vertex: ";
    int start;
    cin>>start;


	clock_t strt = clock();

	visit[start] = 1;
	cout<<start<<" ";
	q.push(start);

	bfs(start, (int*)arr, n, visit);

    clock_t stop = clock();

	cout<<"\nTime required : "<<(double)(stop-strt)<<" ms"<<endl;

    return 0;

}