//  C  program for Dijkstra's  algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 4
#define INF 99999

//function to find the vertex with minimum distance
int minDistance(int dist[], bool sptSet[])
{
    int v = 0;
   // Initialize min value
   int min = INT_MAX, min_index;

   for ( v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
void dijkstra(int graph[V][V], int src)
{
    int i = 0;
    int count = 0;
    int v = 0;
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for ( i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for ( count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for ( v = 0; v < V; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // print the constructed distance array
      printf("Vertex   Distance from Source\n");
      for ( i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

// program to test above function
int main()
{
    int i=0,j=0,s;

      int graph [V][V];
      for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if (i==j) graph[i][j]=0;
            else {
                printf("\nenter distance <%d ,%d>:",i,j);
                scanf("%d",&graph[i][j]);
            }
        }
      }
     source: printf("\nenter source:");
      scanf("%d",&s);
      if(s>=V) goto source;

    dijkstra(graph, s);

    return 0;
}
