//greedy
//nearest neighbour algorithm
//Efficiency n squared
#include <stdio.h>
int arr[100][100],start1,sum=0,count =0;

void nearestNeighbour(int start,int n,int * v){
	int i,min=100000,cur,flag=-1;
	v[start]=1;
	printf("Node %d\t",start+1);
	for(i=0;i<n;i++){
		count ++;
		if(v[i]==0 && i!=start){
			if(arr[start][i]<min){
				min=arr[start][i];
				cur=i;flag=0;
			}
		}
	}
	
	if(flag==-1){
		sum+=arr[start][start1];
		printf("Node %d\nTotal distance is: %d",start1+1,sum);
		
		return;
	}
	
	sum+=arr[start][cur];
	nearestNeighbour(cur,n,v);
}
int main()
{
	int i,j=1,n,start;
	printf("\nNEAREST NEIGHBOUR GREEDY APPROACH:\nEnter no of nodes:\n");
	scanf("%d",&n);int visited[n];
	printf("Enter starting node:\n");
	scanf("%d",&start);
	start--;
	start1=start;   
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			//arr[i][j]=1;
		}
	}
	
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	
	nearestNeighbour(start,n,visited);
	printf("\nCount :%d",count);
	
	return 0;
}
