#include <iostream>
using namespace std;
int dp[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp[1] = 0, dp[2] = 1;
	for (int i = 3; i <= 10; i++) {
		dp[i] = dp[i - 1] + i - 1;
	}

	cout << dp[n];
	return 0;
}
