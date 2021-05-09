#include <iostream>
#include <vector>
using namespace std;

int m, n, tot;
vector<vector<int>> map;
int dp[501][501];
int movex[4] = { 0,0,-1,1 };
int movey[4] = { 1,-1,0,0 };

int dfs(int x,int y) {

	if (x == m - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + movex[i];
		int ny = y + movey[i];

		if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
			if (map[nx][ny] < map[x][y]) {
				dp[x][y] += dfs(nx, ny);
			}
		}
	}
	return dp[x][y];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m >> n;

	map.assign(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
		
	cout<<dfs(0,0);
}
/*
	백준 1520번 내리막 길
*/
