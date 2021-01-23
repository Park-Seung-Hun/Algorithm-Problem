#include <iostream>
using namespace std;

int card[1001];
int dp[1001];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> card[i];

	dp[1] = card[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i - 1;j++) {
			dp[i] = max(dp[j] + card[i - j], dp[i]);
		}
	}
	cout << dp[n];
}

/*
	백준 11052번 카드 구매하기
*/
