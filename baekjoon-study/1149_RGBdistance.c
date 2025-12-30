#include <stdio.h>

typedef struct
{
	int r;
	int g;
	int b;
}RGB;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n;
	int dp[1001][4];
	RGB d[1001];

	scanf("%d", &n);

	for(int i=0;i<n;i++)
		scanf("%d %d %d", &d[i].r, &d[i].g, &d[i].b);

	dp[0][1] = d[0].r;
	dp[0][2] = d[0].g;
	dp[0][3] = d[0].b;

	for(int i=1;i<n;i++){
		dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + d[i].r;
		dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + d[i].g;
		dp[i][3] = min(dp[i-1][2], dp[i-1][1]) + d[i].b;
	}

	int m=1001;
	for(int i=1;i<=3;i++){
		if(dp[n-1][i] < m)
			m = dp[n-1][i];
	}
	printf("%d", m);

	return 0;
}
