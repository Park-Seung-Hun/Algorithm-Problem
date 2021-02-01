#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
char color[100][100];
vector<vector<bool>> check;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };


void bfs(int sx, int sy) {


	queue < pair<int, int>> q;
	q.push(make_pair(sx, sy));
	check[sx][sy] = true;
	char Ref = color[sx][sy];

	while (!q.empty()) {
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n && check[nx][ny] == false && color[nx][ny] == Ref) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			color[i][j] = s[j];
		}
	}

	for (int i = 0; i < 2; i++) {
		check.assign(n, vector<bool>(n, false));
		int sector = 0;
		if (i == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (color[i][j] == 'G') color[i][j] = 'R';
				}
			}
		}

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (check[x][y] == true) continue;
				sector++;
				bfs(x, y);
			}
		}
		cout << sector << ' ';
	}

}
/*
	백준 10026번 적록색약
*/
