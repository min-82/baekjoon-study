#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int n, k, w[101]={0}, v[101]={0}, dp[101][100001] = {0};

int main()
{

	scanf("%d %d", &n, &k);

	for(int i=1;i<=n;i++)
		scanf("%d %d", &w[i], &v[i]);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(w[i] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = MAX(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);
		}
	}

	printf("%d", dp[n][k]);

	return 0;
}
