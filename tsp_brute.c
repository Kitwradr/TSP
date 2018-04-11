//Efficiency n!
#include <stdio.h>
#include <string.h>
int arr[10][10],min=10000000,n;
float count=0.0;
char path[100];

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void permute(char *a, int l, int r)
{
   
   int i;
   if (l == r){
   		count++;
   		int z,sum=0;
   		for(z=1;a[z]!='\0';z++){
   			sum+= arr[a[z-1]-'0'][a[z]-'0'];
   			
		}
		sum+= arr[a[z-1]-'0'][a[0]-'0'];
		if(sum<min)
		{
			min=sum;
			for (i=0;i<n;i++)
			{
				path[i]=a[i];
			}
			
		}
   }
     
     
   else
   {
       for (i = l; i <= r; i++)
       {  
          swap((a+l), (a+i));        
          permute(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}

int main()
{
	int i,j=1,start;
	printf("Enter no of nodes:\n");
	scanf("%d",&n);
	printf("Enter starting node:\n");
	scanf("%d",&start);
	start--;
    char str[100];
    str[0]=start+'0';
    for(i=1;i<n;i++)
	{
    	if('0'+j-1 == start+'0')
		{
    		j++;i--;continue;
		}
		str[i]='0'+j-1;
    	j++;
	}
	
	str[i]='\0';
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
    int num = strlen(str);
    permute(str, 1, num-1);
    printf("\n\nThe shortest path is: %d\n",min);
    printf("Path:\n");
    for (i=0;i<n;i++)
    {
    	printf("%d->",path[i]-'0'+1);
	}
	printf("%d",path[0]-'0'+1);
    printf("\nCount:%f",count);
	return 0;
}
