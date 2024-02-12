#include <stdio.h>
//#include "my_mat.h"
#define MAT_L 10
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF __INT_MAX__

void cr_mat(int graph[MAT_L][MAT_L])
{
    
    for (int i = 0; i< MAT_L; i++)
    {
        for (int j = 0; j < MAT_L; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }    
    //return graph[0][0];
}

int shortPathMat(int g[MAT_L][MAT_L], int u, int v)
{
    int graph[MAT_L][MAT_L];
    int num;
    for (int i = 0; i< MAT_L; i++)
    {
        for (int j = 0; j < MAT_L; j++)
        {
            num = g[i][j];
            graph[i][j] = num;
            if(i!=j && graph[i][j]==0)
            {
                graph[i][j] = INF;
            }
        }
    } 
    for (int k = 0; k<MAT_L; k++)
    {
        for (int i = 0; i<MAT_L; i++)
        {
            for (int j = 0; j<MAT_L; j++)
            {
                
                graph[i][j] = MIN(graph[i][j], graph[i][k] + graph[k][j]);
                
            }

        }
    }
    return graph[u][v];
       
}

int isPath(int g[MAT_L][MAT_L], int u, int v)
{
    
    if (shortPathMat(g,u,v) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int pathWeight(int g[MAT_L][MAT_L], int u, int v)
{
     return shortPathMat(g,u,v);
   
}

