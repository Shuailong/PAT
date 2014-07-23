#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M, N;
    int** matrix;
    int i, j;
    int flag = 0;

    scanf("%d%d", &M, &N);
    matrix = (int**)malloc(sizeof(int*)*M);
    for(i = 0; i < M; ++i){
        matrix[i] = (int*)malloc(sizeof(int)*N);
    }

    for(i = 0; i < M; ++i){
        for(j = 0; j < N; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for(i = 1; i < M-1; ++i){
        for(j = 1; j < N-1; ++j){
            if(matrix[i][j] > matrix[i][j-1]
                    && matrix[i][j] > matrix[i][j+1]
                    && matrix[i][j] > matrix[i-1][j]
                    && matrix[i][j] > matrix[i+1][j]){
                printf("%d %d %d\n", matrix[i][j], i+1, j+1);
                flag = 1;
            }
        }
    }

    if(flag == 0){
        printf("None %d %d\n", M, N);
    }

    for(i = 0; i < M; ++i){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

