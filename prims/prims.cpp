#include<bits/stdc++.h>
using namespace std;
#define V 6

void print(int *prev, int G[][V], int v_max){
	cout<<"Below is the minimal spanning tree :\n";
	cout<<"Edges\tWeights\n";
	for(int i=1;i<v_max;i++){
		cout<< i<<"---"<<prev[i]<<"\t"<<G[i][prev[i]]<<endl;
	}

}
int minweight(int *weight,bool *visited,int v_max){
	int min_val,min_index;
	min_val = INT_MAX;

	for(int i=0;i<v_max;i++){
		if(visited[i]==false && weight[i]<=min_val){
			min_val=weight[i];
			min_index=i;
		}
	}
	return min_index;
}



void prims(int G[][V],int v_max){
	int prev[v_max];
	int weight[v_max];
	bool visited[v_max];


    for(int i=0;i<v_max;i++){
    	weight[i]=INT_MAX;
    	visited[i]=false;
    }
	//choosing 1st element in the graph as the start point
	prev[0]=-1;
	weight[0]=0;

	for(int i=0;i<v_max-1;i++){
		//find the index of vertex u with min weight
		int u = minweight(weight,visited,v_max);

		visited[u]=true;

		//updating the neighbours of the picked vertex
		for(int j=0; j<v_max;j++){
			if(G[u][j]>0 && visited[j]==false && G[u][j]<=weight[j]){
				prev[j]=u;
				weight[j]=G[u][j];
			}
		}
	}
	print(prev, G, v_max);

}
int main(){

  int v_max = 6 ;
  cout<<"WLOG, I am keeping the number of vertices as 6\n";

  int G[V][V]=
  {
  	{0,3,1,2,4,5},
  	{3,0,6,1,2,1},
  	{1,6,0,2,7,4},
  	{2,1,2,0,2,3},
  	{4,2,7,2,0,6},
  	{5,1,4,3,6,0}
  };


  prims(G,v_max);
}