#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > map;
vector<vector<bool> > check;
int w, h, land;

int movex[4] = { 0,0,1,-1 };
int movey[4] = { 1,-1,0,0 };
int movexx[4] = { 1,1,-1,-1 };
int moveyy[4] = { -1,1,-1,1 };

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty()) {
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];

			int nnx = hx + movexx[i];
			int nny = hy + moveyy[i];

			if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
				if (check[nx][ny] == false && map[nx][ny] == 1) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}

			if (nnx >= 0 && nny >= 0 && nnx < h && nny < w) {
				if (check[nnx][nny] == false && map[nnx][nny] == 1) {
					check[nnx][nny] = true;
					q.push(make_pair(nnx, nny));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		land = 0;

		map.assign(h, vector<int>(w, 0));
		check.assign(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && check[i][j] == false) {
					land++;
					bfs(i, j);
				}
			}
		}

		cout << land << '\n';
	}	
}
/*
	백준 4963번 섬의 개수
*/
