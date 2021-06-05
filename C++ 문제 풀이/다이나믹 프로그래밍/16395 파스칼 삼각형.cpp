#include <iostream>
using namespace std;
int dp[31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	dp[0][0] = dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	cin >> n >> k;

	cout << dp[n - 1][k - 1];
	return 0;
}
