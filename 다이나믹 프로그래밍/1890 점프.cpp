#include <iostream>
using namespace std;

int box[100][100];
long long dp[100][100];
bool flag[100][100];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n ;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> box[i][j];
	
	dp[0][0] = 1;
	flag[0][0] = true;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (box[x][y] == 0 || flag[x][y] == false) continue;

			if (x + box[x][y] < n) {
				dp[x + box[x][y]][y] = max(dp[x + box[x][y]][y], dp[x][y] + dp[x + box[x][y]][y]);
				flag[x + box[x][y]][y] = true;
			}
			if (y + box[x][y] < n) {
				dp[x][y + box[x][y]] = max(dp[x][y + box[x][y]], dp[x][y] + dp[x][y + box[x][y]]);
				flag[x][y + box[x][y]] = true;
			}

		}
	}
	cout << dp[n-1][n-1];
}

/*
	백준 1890번 점프
*/
