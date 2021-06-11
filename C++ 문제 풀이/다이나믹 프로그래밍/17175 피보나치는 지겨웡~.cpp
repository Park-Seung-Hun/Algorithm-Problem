#include <iostream>
using namespace std;
int dp[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp[0] = dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
	}

	cout << dp[n] << '\n';
	return 0;
}
