#include <iostream>
#include <queue>
using namespace std;

char box[250][250];
bool check[250][250];
int X[4] = { 0,0,-1,1 };
int Y[4] = { 1,-1,0,0 };
int w, s;
int n, m;

void bfs(int i, int j) {
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	int rw = 0, rs = 0;
	check[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		if (box[x][y] == 'v') { rw++; }
		else if (box[x][y] == 'k') { rs++; }
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + X[k];
			int ny = y + Y[k];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && check[nx][ny] == false) {
				if (box[nx][ny] != '#') {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	if (rs > rw) w -= rw;
	else s -= rs;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string text;
		cin >> text;
		for (int j = 0; j < m; j++) {
			box[i][j] = text[j];
			if (text[j] == 'v') w++;
			if (text[j] == 'k') s++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 'k' || box[i][j] == 'v') {
				if (check[i][j] == false) {
					bfs(i, j);
				}
			}
		}
	}

	cout << s << ' ' << w;
}

/*
	백준 3178번 양치기 꿍
*/

