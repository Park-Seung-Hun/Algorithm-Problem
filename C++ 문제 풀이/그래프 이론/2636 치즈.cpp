/*

*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> v;
vector<pair<int, int>> save;
vector<vector<bool>> c;
bool flag;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	c[x][y] = true;

	while (!q.empty()) {
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위를 벗어나는 곳
			if (c[nx][ny]) continue; // 방문한 적 있는 곳
			if (v[nx][ny] == 0) q.push({ nx,ny }); // 0인 곳 넣기
			else { // 1인곳 넣기
				save.push_back({ nx,ny });
				flag = true;
			}
			c[nx][ny] = true;
		}

	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m ;

	// 초기화
	v.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int ans = 0;
	int cnt;
	while (true) {
		c.assign(n, vector<bool>(m, false));
		flag = false;
		bfs(0, 0);
		if(flag)cnt = 0;

		for (int i = 0; i < save.size(); i++) {
			int x = save[i].first;
			int y = save[i].second;
			cnt++;
			v[x][y] = 0;
		}
		save.clear();
		if (!flag) break;
		ans++;
	}
	cout << ans << '\n';
	cout << cnt << '\n';
	return 0;
}
