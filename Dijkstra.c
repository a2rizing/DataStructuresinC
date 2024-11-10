#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10
#define INF INT_MAX
void addEdge(int graph[MAX][MAX], int u, int v, int weight)
{
    graph[u][v] = weight;
}
void dijkstra(int src, int graph[MAX][MAX], int n)
{
    int dist[MAX];
    int visited[MAX] = {0};
    int parent[MAX];
    for(int i = 0;i<n;i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;
    for(int i = 0;i<n-1;i++)
    {
        int minDist = INF, u;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for(int v = 0;v<n;v++)
        {
            if(!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printf("Shortest distances from Source: %d\n",src);
    for(int i = 0;i<n;i++)
    {
        printf("Node %d: %d\n",i,dist[i]);
    }
}
int main()
{
    printf("Enter number of vertices: ");
    int n,e;
    int graph[MAX][MAX];
    scanf("%d",&n);
    printf("Enter number of edge: ");
    scanf("%d",&e);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            graph[i][j] = INF;
        }
    }
    printf("Enter the Directional Edges and Weight: \n");
    for(int i = 0;i<e;i++)
    {
        int u,v,weight;
        scanf("%d %d %d",&u,&v,&weight);
        addEdge(graph,u,v,weight);
    }
    int src;
    printf("Enter source node: ");
    scanf("%d",&src);
    dijkstra(src, graph, n);
    return 0;
}