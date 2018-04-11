#include<stdlib.h>
#include<stdio.h>
//using namespace std;
//#define INT_MAX 999999
int n;
int dist[100][100];
int VISITED_ALL ;
int dp[16][4];
int count;//bit shift

int tsp(int mask,int pos)
{
int city;
count++;
if(mask==VISITED_ALL)
{
 return dist[pos][0];
}
count++;
if(dp[mask][pos]!=-1)
{
 return dp[mask][pos];
}
//Now from current node, we will try to go to every other node and take the min ans
int ans = 999999;
//Visit all the unvisited cities and take the best route
for(city=0;city<n;city++){
 count++;
 count+=2;//for shifting and comparing bitwise
 if((mask&(1<<city))==0){
 int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
 count+=3;//shift and OR

 count++;//to find min
 ans =(ans<newAns)?ans:newAns;

 }
}

return dp[mask][pos] = ans;
}
int main()
{
	int i,j;
 /* init the dp array */
 printf("Enter n:");
 scanf("%d",&n);
 printf("Enter adj matrix:\n");
 for (i=0;i<n;i++)
 {
 	for (j=0;j<n;j++)
 	{
 		scanf("%d",&dist[i][j]);
	}
 }
 VISITED_ALL = (1<<n) -1;
 count=n;
 for(i=0;i<(1<<n);i++)
 {
 	for(j=0;j<n;j++){
 	dp[i][j] = -1;
 	}	
 }
 printf("Travelling Salesman Distance is %d\n",tsp(1,0));
 printf("Count is :%d",count);
 return 0;
}

