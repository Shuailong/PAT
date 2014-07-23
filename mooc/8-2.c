#include <stdio.h>
#include <stdlib.h>

int main()
{
	int M, N;
	int** m;
	int i, j;
	int flag = 0;

	scanf("%d%d", &M, &N);
	m = (int**)malloc(sizeof(int*)*M);
	for(i = 0; i < M; ++i){
		m[i] = (int*)malloc(sizeof(int)*N);
	}

	for(i = 0; i < M; ++i){
		for(j = 0; j < N; ++j){
			scanf("%d", &m[i][j]);
		}
	}

	for(i = 1; i < M-1; ++i){
		for(j = 1; j < N-1; ++j){
			if(m[i][j] > m[i][j-1] &&
				m[i][j] > m[i][j+1] &&
				m[i][j] > m[i-1][j] &&
				m[i][j] > m[i+1][j]){
				printf("%d %d %d\n", m[i][j], i+1, j+1);
				flag = 1;
			}
		}
	}
	if(flag == 0){
		printf("None %d %d\n", M, N);
	}

	for(i = 0; i < M; ++i){
		free(m[i]);
	}
	free(m);

	return 0;
}