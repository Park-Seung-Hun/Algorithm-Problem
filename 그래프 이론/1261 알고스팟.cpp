#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int> > wall;
vector<vector<int> > ans;
int movex[4] = { 0,0,-1,1 };
int movey[4] = { 1,-1,0,0 };

void bfs() {
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	ans[0][0] = 0;

	while (!q.empty()) {
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (wall[nx][ny] == 1 && ans[nx][ny] > ans[hx][hy] + 1) {
					ans[nx][ny] = ans[hx][hy] + 1;
					q.push(make_pair(nx, ny));
				}
				else if (wall[nx][ny] == 0 && ans[nx][ny] > ans[hx][hy]) {
					ans[nx][ny] = ans[hx][hy];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;

	wall.assign(n, vector<int>(m, 0));
	ans.assign(n, vector<int>(m, 987654321));

	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < m; j++) {
			wall[i][j] = t[j] - '0';
		}
	}

	bfs();
	cout << ans[n - 1][m - 1];
}
/*
	백준 1261번 알고스팟
*/
