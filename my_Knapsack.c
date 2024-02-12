#include <stdio.h>
#define SIZEP 5
#define MAXW 20
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int knapsack(int values[SIZEP], int weights[SIZEP], int selected_bool[SIZEP])
{
    
    int valueBefore;
    int weightBefore;
    int matrix[SIZEP+1][MAXW+1];
    for (int i = 0; i < SIZEP; i++)
    {
        for (int j = 0; j < MAXW; j++)
        {
            matrix[i][j] = 0;
        }
        
    }
    
    for (int i = 1; i <= SIZEP; i++)
    {
        for (int j = 1; j <= MAXW; j++)
        {
            valueBefore = values[i-1];
            weightBefore = weights[i-1];
            if (weightBefore <= j)
            {
                matrix[i][j] = MAX(valueBefore + matrix[i-1][j-weightBefore], matrix[i-1][j]);
            }
            else
            {
                matrix[i][j] = matrix[i][j-1];
            }
        }

    }
    printf("Maximum profit: %d\n", matrix[SIZEP][MAXW]);

    int i = SIZEP;
    int j = MAXW;
    while (i > 0 && j > 0)
    {
        if (matrix[i][j] != matrix[i-1][j])
        {
            selected_bool[i-1] = 1;
            j -= weights[i-1];
        }
        i--;
    }
    printf("Selected items:");
    for (int i = 0; i < SIZEP; i++)
    {
        if ((selected_bool[i]) == 1)
        {
            if (i == 0)
            {
                printf(" a");
            }
            if (i == 1)
            {
                printf(" b");
            }
            if (i == 2)
            {
                printf(" c");
            }
            if (i == 3)
            {
                printf(" d");
            }
            if (i == 4)
            {
                printf(" e");
            }
            
        }
        
        
    }
    return matrix[SIZEP][MAXW];

}

int main ()
{
    //char products[SIZEP][MAXW+1];
    char act;
    int num;
    int selected_bool[SIZEP] = {0, 0, 0, 0, 0};
    int values[SIZEP];
    int weights[SIZEP];
    for (int i = 0; i < SIZEP; i++)
    {
        scanf(" %c", &act);
        if (act == 'a')
        {
            scanf("%d", &num);
            values[0] = num;
            scanf("%d", &num);
            weights[0] = num;
        }
        if (act == 'b')
        {
            scanf("%d", &num);
            values[1] = num;
              scanf("%d", &num);
              weights[1] = num;
        }
        if (act == 'c')
        {
            scanf("%d", &num);
            values[2] = num;
            scanf("%d", &num);
            weights[2] = num;
        }
        if (act == 'd')
        {
            scanf("%d", &num);
            values[3] = num;
            scanf("%d", &num);
            weights[3] = num;
        }
        if (act == 'e')
        {
            scanf("%d", &num);
            values[4] = num;
            scanf("%d", &num);
            weights[4] = num;
        }
        
       
    }
    knapsack(values, weights, selected_bool);



    
}