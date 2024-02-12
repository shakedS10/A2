#include <stdio.h>
#pragma once
#define MAT_L 10

void cr_mat(int graph[MAT_L][MAT_L]);
int shortPathMat(int g[MAT_L][MAT_L], int u, int v);
int isPath(int g[MAT_L][MAT_L], int u, int v);
int pathWeight(int g[MAT_L][MAT_L], int u, int v);
