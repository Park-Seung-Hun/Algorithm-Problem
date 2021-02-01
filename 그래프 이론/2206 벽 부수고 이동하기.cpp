#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m,ans;
vector<vector<int> > wall;
bool visit[1000][1000][2];

int movex[4] = { 0,0,-1,1 };
int movey[4] = { 1,-1,0,0 };

void bfs() {
	queue<pair<pair<int,int>, pair<int,int> > > q;
	q.push(make_pair(make_pair(0, 0),make_pair(0,1)));
	visit[0][0][0] = true;

	while (!q.empty()) {
		int hx = q.front().first.first;
		int hy = q.front().first.second;
		int cost = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		
		if (hx == n - 1 && hy == m - 1) {
			ans = cnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (wall[nx][ny] == 1 && cost == 0) {
					visit[nx][ny][cost + 1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(cost + 1, cnt + 1)));
				}
				else if (wall[nx][ny] == 0 && visit[nx][ny][cost] == false) {
					visit[nx][ny][cost] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(cost, cnt + 1)));
				}
			}
		}
		
	}
	ans = -1;
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	wall.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < m; j++) {
			wall[i][j] = t[j] - '0';
		}
	}

	bfs();

	cout << ans << '\n';
}
/*
	백준 2206번 벽 부수고 이동하기
*/
