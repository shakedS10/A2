#include <stdio.h>
#include "my_mat.h"


int main (void)
{
    
    int graph[MAT_L][MAT_L];
    //int shortPmat[MAT_L][MAT_L];
    char act ;
    scanf("%c", &act);
    while (act != 'D')
    {
        if(act == EOF)
        {
            break;
        }
        if(act == 'A')
        {
            cr_mat(graph);
            //shortPmat[0][0] = shortPathMat(graph);
        }
        if (act == 'B')
        {
            int i ;
            scanf("%d", &i);
            int j;
            scanf("%d", &j);
            
            int a = shortPathMat(graph,i,j);
            printf("%d" , a);
            if (isPath(graph, i, j) == 0)
            {
                printf("False\n");
            }
            else 
            {
                printf("True\n");
            }
            
        }
        if (act == 'C')
        {
            int i;
             scanf("%d", &i);
             printf("%d", i);
            int j;
            scanf("%d", &j);
            printf("%d", j);
            int weight = pathWeight(graph, i, j);
            if(weight == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", weight);
            }
        }
        scanf("%c", &act);
    
    }
    return 0;
}
