#include <iostream>
using namespace std;

long long grape[10001];
long long dp[10001][3];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> grape[i];

	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = dp[i - 1][0] + grape[i];
		dp[i][2] = dp[i - 1][1] + grape[i];
	}

	long long ans = max(dp[n][0],max(dp[n][1],dp[n][2]));
	cout << ans << '\n';
}

/*
	백준 2156번 포도주
*/
