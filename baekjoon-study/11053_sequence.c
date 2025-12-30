#include <stdio.h>

int max(int a, int b) {return a > b ? a : b;}

int main()
{
	int n, maximum=0, num[1001], dp[1001];
	scanf("%d", &n);

	for(int i=0;i<n;i++)
		scanf(" %d", &num[i]);

	for (int i = 0; i < n; i++) {
    	dp[i] = 1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(num[i] > num[j]){
				if(dp[i] < dp[j] + 1)
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for(int i=0;i<n;i++)
		if(maximum < dp[i])
			maximum = dp[i];

	printf("%d", maximum);

	return 0;
}
