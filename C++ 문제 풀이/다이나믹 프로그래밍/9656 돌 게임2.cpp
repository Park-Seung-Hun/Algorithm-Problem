#include <iostream>
using namespace std;
string dp[1031];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string ans = "SK";
	for (int i = 0; i <= 1000; i++) {
		if (ans == "CY") {
			dp[i + 1] = "SK";
			dp[i + 3] = "SK";
			ans = "SK";
		}
		else {
			dp[i + 1] = "CY";
			dp[i + 3] = "CY";
			ans = "CY";
		}
	}

	cout << dp[n];
	return 0;
}
