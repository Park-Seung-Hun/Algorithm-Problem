#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> num;
vector<vector<long long>> dp;
int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	
	for (int test = 0; test < t; test++) {
		cin >> n; 
		num.assign(n+1, vector<long long>(2, 0));
		dp.assign(n+1, vector<long long>(3, 0));

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> num[j][i];
			}
		}
		
		dp[0][0] = dp[0][1] = dp[0][2] = 0;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + num[i][0];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + num[i][1];
		}

		long long ans = 0;
		for (int i = 1; i <= n; i++) ans = max(max(ans, dp[i][0]), max(dp[i][1], dp[i][2]));
		cout << ans << '\n';
	}
}

/*
	백준 9465번 스티커
*/
