#include <iostream>
using namespace std;

int ans = -987654321;
int n;
int dp[100000];
int num[100000];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> num[i];

	dp[0] = num[0];
	for (int i = 1; i < n; i++) dp[i] = max(dp[i - 1] + num[i], num[i]);
	for (int i = 0; i < n; i++) if (ans < dp[i]) ans = dp[i];
	cout << ans;
}

/*
	백준 1912번 연속합
*/
