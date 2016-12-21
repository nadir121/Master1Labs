#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define INF 999

int a,b,u,v,n,i,j,ne=1,choice;
int visited[10]={0},min,mincost=0,cost[10][10],parent[10];
void prim(){
        printf("\n\tImplementation of Prim's algorithm\n");

	printf("The edges of Minimum Cost Spanning Tree are\n");
	visited[1]=1;
	printf("\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< min)
		if(visited[i]!=0)
		{
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n Minimun cost=%d",mincost);
	getch();
    }
    void kruskall(){
		printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	getch();
	}
	int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
int main()
{
  start: ne=1,mincost=0;
  for(i=0;i<10;i++) visited[i]=0;
        printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
			cost[i][j]=INF;
	}
    printf("\n1)Prim's Algorithm\n2)Kruskall's Algorithm\n");
    scanf("%d",&choice);
    if (choice==1) prim();
    else if (choice==2) kruskall();
    else printf("No such choice");
    goto start;
    return 0;
}
