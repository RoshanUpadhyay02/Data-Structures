#include <stdio.h>
#include <stdlib.h>

int n, visited[100],G[100][100];

void DFS(int s)
{
    int i;
    printf("%d ",s);
    /*switch (s) // Specific to the graph  given by sir.
    {
    case 0:
        printf("\nTraversal of the graph is: \n");
        break;
    case 1:
        printf("B ");
        break;
    case 2:
        printf("C ");
        break;
    case 3:
        printf("D ");
        break;
    case 4:
        printf("E ");
        break;
    }*/

    visited[s] = 1;
    
    for(i=0;i<n;i++)
    {
        if(G[s][i]  == 1 && visited[i] != 1)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i,j,x;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matix of the graph: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    }

    for(i=0;i<n;i++)
        visited[i] = 0; 

    printf("Enter the starting vertex: ");
    scanf("%d",&x);

    printf("\nDFS Traversal of the graph is: ");
    DFS(x);
    return 0;
}