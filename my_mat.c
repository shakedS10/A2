#include <stdio.h>
//#include "my_mat.h"
#define MAT_L 10
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF __INT_MAX__
int sp_graph[MAT_L][MAT_L];

void shortPathMat(int g[MAT_L][MAT_L])
{
    //int graph[MAT_L][MAT_L];
    int num;
    for (int i = 0; i< MAT_L; i++)
    {
        for (int j = 0; j < MAT_L; j++)
        {
            
            sp_graph[i][j] = g[i][j];
           
        }
    } 
    for (int k = 0; k<MAT_L; k++)
    {
        for (int i = 0; i<MAT_L; i++)
        {
            for (int j = 0; j<MAT_L; j++)
            {
                
               if(sp_graph[i][k]!=0 && sp_graph[k][j]!=0)
               {
                   num = MIN(sp_graph[i][j], sp_graph[i][k]+sp_graph[k][j]);
                   if(num != sp_graph[i][j] || sp_graph[i][j]==0)
                   {
                       sp_graph[i][j] = sp_graph[i][k]+ sp_graph[k][j];
                   }   
               }
                
            }

        }
    }
    //return sp_graph[u][v];
       
}

void cr_mat(int graph[MAT_L][MAT_L])
{
    
    for (int i = 0; i< MAT_L; i++)
    {
        for (int j = 0; j < MAT_L; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    } 
    shortPathMat(graph);   
    //return graph[0][0];
}


int isPath(int u, int v)
{
    
    if (sp_graph[u][v] == 0 || u == v)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int getweight(int u, int v)
{
    if(sp_graph[u][v] == 0 || u==v)
    {
        return -1;
    }
    else
    {
        return sp_graph[u][v];
    }
}


