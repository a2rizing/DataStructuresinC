#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
void bfs(int src, int graph[MAX][MAX], int n)
{
    int front = 0, rear = 0;
    int visited[MAX] = {0};
    int queue[MAX];
    queue[rear++] = src;
    visited[src] = 1;
    while(front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);
        for(int neighbour = 0;neighbour<n;neighbour++)
        {
            if(graph[current][neighbour] && !visited[neighbour])
            {
                visited[neighbour] = 1;
                queue[rear++] = neighbour;
            }
        }
    }
}

void dfs(int src, int graph[MAX][MAX], int n, int visited[MAX])
{
    visited[src] = true;
    printf("%d ", src);
    for(int i = 0;i<n;i++)
    {
        if(graph[src][i] && !visited[i])
        {
            dfs(i,graph,n,visited);
        }
    }
}
int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int graph[MAX][MAX] = {0};
    printf("Enter adjacency matrix: ");
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Starting from node 0: \n");
    int src = 0;
    int visited[MAX] = {0};
    printf("The BFS of the given graph: ");
    bfs(src, graph, n);
    printf("\n\nThe DFS of the given graph: ");
    dfs(src,graph,n,visited);
}