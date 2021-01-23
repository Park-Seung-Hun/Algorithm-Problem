#include <iostream>
using namespace std;

int dp[1001];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0] = dp[1] = 1;
	
	cin >> n;

	for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + 2*dp[i - 2])%10007;

	cout << dp[n];
	
}

/*
	백준 11727번 2xn 타일링 2
*/
