#include <stdio.h>
#include <string.h>

int max(int a, int b) {return a > b ? a : b;}

int dp[1001][1001];

int main()
{
	char a[1001], b[1001];

	scanf("%s %s", a ,b);

	int len_a = strlen(a);
	int len_b = strlen(b);

	for(int i=1;i<=len_a;i++){
		for(int j=1;j<=len_b;j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	printf("%d", dp[len_a][len_b]);

	return 0;
}
