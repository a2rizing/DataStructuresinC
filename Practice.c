#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void addEdge(int graph[MAX][MAX], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void bfs(int src, int graph[MAX][MAX], int V, int target)
{
    int queue[MAX], rear = 0, front = 0;
    int visited[MAX] = {0};
    visited[src]=1;
    queue[rear++] = src;
    int levelnumber = 0;
    while(front < rear)
    {
        int node = queue[front++];
        if(node==target){
            printf("Level Number : %d",levelnumber);
            return;
        }
        for(int i = 0;i<V;i++)
        {
            if(graph[node][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
        levelnumber++;
    }
    printf("-1");
}
int main()
{
    int n;
    printf("Enter vertices: ");
    scanf("%d",&n);
    int e;
    printf("Enter edges: ");
    scanf("%d",&e);
    int graph[MAX][MAX] = {0};
    for(int i = 0;i<e;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(graph,u,v);
    }
    int x;
    scanf("%d",&x);
    bfs(0,graph,n,x);
}