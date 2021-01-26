#include <iostream>
using namespace std;

long long dp[10001][4];
int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	dp[0][1] = 1;
	for (long long i = 1; i <= 10000; i++) {
		dp[i][1] = dp[i - 1][1];
		if (i > 1) dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if (i > 2) dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];

	}

	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n;

		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';;
	}
}

/*
	백준 15989번 1,2,3 더하기 4
*/
