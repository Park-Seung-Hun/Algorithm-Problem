#include <iostream>
using namespace std;

int x;
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x;


	for (int i = 1; i <= x; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[x];
}


/*
	백준 1699번 제곱수의 합
*/
