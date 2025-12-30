#include <stdio.h>

int main()
{
	int n, k, c[101]={0}, dp[10001]={0};

	scanf("%d %d", &n, &k);

	for(int i=1;i<=n;i++)
		scanf("%d", &c[i]);
	dp[0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=c[i];j<=k;j++){
			dp[j] = dp[j] + dp[j - c[i]];
		}
	}

	printf("%d", dp[k]);

	return 0;
}
