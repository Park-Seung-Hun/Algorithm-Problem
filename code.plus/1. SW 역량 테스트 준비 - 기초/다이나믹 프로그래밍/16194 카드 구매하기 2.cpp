#include <iostream>
#include <vector>
using namespace std;

int card[1001];
vector<int> dp;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dp.assign(n + 1, 987654321);
	for (int i = 1; i <= n; i++) cin >> card[i];

	dp[0] = 0;
	dp[1] = card[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i - 1;j++) {
			dp[i] = min(dp[j] + card[i - j], dp[i]);
		}
	}
	cout << dp[n];
}

/*
	백준 16194번 카드 구매하기 2
*/
