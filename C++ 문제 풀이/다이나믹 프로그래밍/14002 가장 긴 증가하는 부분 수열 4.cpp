#include <iostream>
#include <vector>
using namespace std;

int num[1000];
int dp[1000];
vector<int> save[1000];
int n, ans;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> num[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		save[i].push_back(num[i]);

		int idx = 1;
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j]) {
				if (dp[i] < dp[j] + 1) {
					save[i] = save[j];
					save[i].push_back(num[i]);
					dp[i] = dp[j] + 1;
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		if (save[i].size() == ans) {
			for (int j = 0; j < ans; j++) cout << save[i][j]<<' ';
			break;
		}
	}
}

/*
	백준 14002번 가장 긴 증가하는 부분 수열 4
*/
