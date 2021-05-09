#include <iostream>
#include <vector>
using namespace std;

int n, k;
int dp[1001][1001];

int main() {
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j <= i-1; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;

		}
	}

	cout << dp[n][k] % 10007;
}
