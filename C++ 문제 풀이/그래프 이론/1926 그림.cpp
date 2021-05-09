#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> pic;
vector<vector<bool>> check;
int ans, MAX, n, m;
int movex[4] = { 0,0,-1,1 };
int movey[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	int tot = 1;
	while (!q.empty()) {
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && check[nx][ny] == false && pic[nx][ny] == 1) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
				tot++;
			}
		}
	}

	if (tot > MAX) MAX = tot;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	pic.assign(n, vector<int>(m, 0));
	check.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> pic[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pic[i][j] == 1 && check[i][j] == false) {
				ans++;
				bfs(i, j);
			}
		}
	}
	cout << ans << '\n' << MAX << '\n';
}
/*
	백준 1926번 그림
*/
