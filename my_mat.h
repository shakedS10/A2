#include <stdio.h>
#pragma once
#define MAT_L 10

void cr_mat(int graph[MAT_L][MAT_L]);
void shortPathMat(int g[MAT_L][MAT_L]);
int isPath( int u, int v);
int getweight(int u, int v);
