#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

vector<vector<int> > miro;
vector<vector<int> > ans;
vector<vector<bool> > check;

int movex[4] = { 0,0,1,-1 };
int movey[4] = { 1,-1,0,0 };

void bfs(int x,int y, int cnt) {
	queue<pair<pair<int,int>, int> > q;
	q.push(make_pair(make_pair(x, y),cnt));
	check[x][y] = true;
	ans[x][y] = cnt;

	while (!q.empty()) {
		int hx = q.front().first.first;
		int hy = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (check[nx][ny] == false && miro[nx][ny] == 1) {
					check[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), cost + 1));
					if (cost + 1 < ans[nx][ny]) ans[nx][ny] = cost + 1;
				}
			}
		}
	
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	miro.assign(n + 1, vector<int>(m + 1, 0));
	ans.assign(n + 1, vector<int>(m + 1, 987654321));
	check.assign(n + 1, vector<bool>(m + 1, false));

	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;

		for (int j = 0; j < m; j++) {
			miro[i][j] = t[j] - '0';
		}
	}
	bfs(0, 0, 1);

	cout << ans[n - 1][m - 1];
}
/*
	백준 2178번 미로 탐색
*/
