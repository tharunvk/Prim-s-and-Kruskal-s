#include<bits/stdc++.h>
using namespace std;
#define V 9
int parent_array[9];

int find(int v)
{
	while(parent_array[v])
	v=parent_array[v];
	return v;
}
int my_union(int u,int v)
{
	if(u!=v)
	{
		parent_array[v]=u;
		return 1;
	}
	return 0;
}

int main(){
	cout<<"Kruskal's MST!!!\n";
	int v_max = 6 ;
	int u,v,a,b;
	int min,min_cost=0;
	cout<<"WLOG, I am keeping the number of vertices as 6\n";

  int parent_array[9];
  int cost[9][9];
	for(int i=1;i<=v_max;i++)
	{
		for(int j=1;j<=v_max;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	for(int i=1;i<=v_max;i++)
	{
		for(int j=1;j<=v_max;j++)
		{
			cout<<cost[i][j]<<" ";
	
		}
		cout<<endl;
	} 
  cout<<"Below is the Minimal spanning tree\n";
  cout<<"Edges\n";

  int count=1;
  while(count<v_max){
  	for(int i=1,min=999;i<=v_max;i++){
  		for(int j=1;j<=v_max;j++){
  			if(cost[i][j]< min){
  				min = cost[i][j];
  				a=u=i;
  				b=v=j;
  			}
  		}
  	}
  	u = find(u);
  	v = find(v);
  	if(my_union(u,v)){
  		cout<< a<<"---"<<b<<endl;
  		min_cost+=min;
  	}
  	cost[a][b] = 999;
  	cost[b][a] = 999;
  	count++;
  }
  return 0;
}