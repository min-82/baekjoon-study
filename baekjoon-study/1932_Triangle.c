#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int n, m=0, num[501][501];
	scanf("%d", &n);

	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++)
			scanf(" %d", &num[i-1][j]);
	}

	int **val = (int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
		val[i] = (int*)malloc(sizeof(int)*(i+1));

	val[0][0] = num[0][0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j==0)
				val[i][j] = val[i-1][j] + num[i][j];
			else if(j==i)
				val[i][j] = val[i-1][j-1] + num[i][j];
			else    
				val[i][j] = max(val[i-1][j-1], val[i-1][j]) + num[i][j];
		}
	}

	for(int i=0;i<n;i++){
		if(val[n-1][i] > m)
			m = val[n-1][i];
	}

	printf("%d", m);

	for(int i = 0; i < n; i++) free(val[i]);
	free(val);

	return 0;
}
