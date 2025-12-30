#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    int s[301] = {0};
    int dp[301] = {0};

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }

    // 초깃값 설정 (Base Case)
    dp[1] = s[1];
    if (n >= 2) {
        dp[2] = s[1] + s[2];
    }
    if (n >= 3) {
        // 3번째 계단: (1번+3번) vs (2번+3번)
        dp[3] = MAX(s[1] + s[3], s[2] + s[3]);
    }

    // 점화식 실행 (4번째 계단부터)
    for (int i = 4; i <= n; i++) {
        dp[i] = MAX(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]);
    }

    printf("%d\n", dp[n]);

    return 0;
}
