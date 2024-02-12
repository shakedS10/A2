#include <stdio.h>
#include <string.h>
#define SIZEP 5
#define MAXW 20
#define MAX(a, b) ((a) > (b) ? (a) : (b))
char products[SIZEP][MAXW+1];
int knapsack(int values[SIZEP], int weights[SIZEP], int selected_bool[SIZEP])
{
    
    int valueBefore;
    int weightBefore;
    int matrix[SIZEP+1][MAXW+1];
    for (int i = 0; i <= SIZEP; i++)
    {
        for (int j = 0; j <= MAXW; j++)
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
                printf(" %s", products[0]);
            }
            if (i == 1)
            {
                printf(" %s", products[1]);
            }
            if (i == 2)
            {
                printf(" %s", products[2]);
            }
            if (i == 3)
            {
                printf(" %s", products[3]);
            }
            if (i == 4)
            {
                printf(" %s", products[4]);
            }
            
        }
        
        
    }
    return matrix[SIZEP][MAXW];

}

int main ()
{
    
    
    //char act;
    int num;
    int selected_bool[SIZEP] = {0, 0, 0, 0, 0};
    int values[SIZEP];
    int weights[SIZEP];
    for (int i = 0; i < SIZEP; i++)
    {
        scanf("%s", products[i]);
        scanf("%d", &num);
        values[i] = num;
        scanf("%d", &num);
        weights[i] = num;  
    }
    knapsack(values, weights, selected_bool);



    
}