#include <stdio.h>
#include "my_mat.h"


int main (void)
{
    
    int graph[MAT_L][MAT_L];
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
        }
        if (act == 'B')
        {
            int i ;
            scanf("%d", &i);
            int j;
            scanf("%d", &j);
            if (isPath( i, j) == 0)
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
            int j;
            scanf("%d", &j);
            int weight = getweight(i,j);
            if(weight == 0 || i==j)
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
