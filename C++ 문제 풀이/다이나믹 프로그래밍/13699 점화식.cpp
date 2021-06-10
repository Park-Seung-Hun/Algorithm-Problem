/*
13699 점화식
sol. DP
*/

#include <iostream>
#include <vector>
using namespace std;
long long dp[35],N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	dp[0] = dp[1] = 1;

	for (long long i = 2; i <= N; i++) {

		for (long long j = 0; j < i; j++) {
			dp[i] += dp[i - j - 1] * dp[j];
		}
	}

	cout << dp[N] << '\n';
	return 0;
}
