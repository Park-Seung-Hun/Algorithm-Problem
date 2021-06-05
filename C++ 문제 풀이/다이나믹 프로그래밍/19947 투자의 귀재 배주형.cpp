/*
  이자 문제 = DP로 푸는게 최고다.
*/

#include <iostream>
#include <cmath>
using namespace std;
int dp[100];
int h, y;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> y;
	dp[0] = h;

	for (int i = 0; i <= y; i++) {
		dp[i + 1] = max(dp[i + 1], (int)(dp[i] + dp[i] * 0.05));
		dp[i + 3] = max(dp[i + 3], (int)(dp[i] + dp[i] * 0.2));
		dp[i + 5] = max(dp[i + 5], (int)(dp[i] + dp[i] * 0.35));
	}
	cout << dp[y];
	return 0;
}
