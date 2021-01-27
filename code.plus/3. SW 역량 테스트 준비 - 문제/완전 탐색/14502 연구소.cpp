#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, MAX;
vector<vector<int>> map;
vector<vector<int>> r;
vector<vector<bool>> check;
vector<vector<bool>> wcheck;
int movex[4] = { 0,0,-1,1 };
int movey[4] = { 1,-1,0,0 };


void bfs(int x,int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	wcheck[x][y] = true;

	while (!q.empty()) {
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && wcheck[nx][ny] == false && r[nx][ny] == 0) {
				wcheck[nx][ny] = true;
				r[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void wall(int cnt) {

	if (cnt == 3) {
		wcheck.assign(n, vector<bool>(m, false));
		r = map;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (r[i][j] == 2 && wcheck[i][j] == false) {
					bfs(i, j);
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (r[i][j] == 0) ans++;
			}
		}
		if (ans > MAX) MAX = ans;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && check[i][j] == false) {
				map[i][j] = 1;
				check[i][j] = true;
				wall(cnt + 1);
				check[i][j] = false;
				map[i][j] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	map.assign(n, vector<int>(m, 0));
	r.assign(n, vector<int>(m, 0));
	check.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	wall(0);

	cout << MAX << '\n';
}
/*
	백준 14502번 연구소
*/
