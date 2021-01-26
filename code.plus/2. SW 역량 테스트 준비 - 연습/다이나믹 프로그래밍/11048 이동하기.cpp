#include <iostream>
using namespace std;

int candy[1001][1001];
int dp[1001][1001];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> candy[i][j];

	dp[1][1] = candy[1][1];

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (x + 1 <= n && y + 1 <= m) dp[x + 1][y + 1] = max(dp[x + 1][y + 1], dp[x][y] + candy[x + 1][y + 1]);
			if (y + 1 <= m) dp[x][y + 1] = max(dp[x][y + 1], dp[x][y] + candy[x][y + 1]);
			if (x + 1 <= n) dp[x + 1][y] = max(dp[x + 1][y], dp[x][y] + candy[x + 1][y]);
		}
	}
	cout << dp[n][m];
}

/*
	백준 11048번 이동하기
*/
