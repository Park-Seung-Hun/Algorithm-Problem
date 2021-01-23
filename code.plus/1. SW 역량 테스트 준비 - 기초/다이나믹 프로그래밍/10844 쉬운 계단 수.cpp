#include <iostream>
using namespace std;
#define Ref 1000000000

long long dp[101][11];
long long n, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (long long i = 1; i <= 9; i++) dp[1][i] = 1;
	dp[1][0] = 0;

	for (long long i = 2; i <= n; i++) {
		for (long long j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % Ref;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % Ref;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Ref;
		}
	}

	for (long long i = 0; i < 10; i++) ans += dp[n][i];
	cout << ans%Ref << '\n';
}

/*
	백준 10844번 쉬운 계단 수
*/
