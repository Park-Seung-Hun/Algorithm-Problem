#include <iostream>
#include <queue>
using namespace std;

int k, w, h;

int box[200][200];
bool check[200][200][31];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ddx[] = { 1,1,-1,-1,2,2,-2,-2 };
int ddy[] = { 2,-2,2,-2,1,-1,1,-1 };

void bfs(int sx, int sy) {
	queue<pair<pair<int,int>, pair<int,int>>> q;
	q.push(make_pair(make_pair(sx, sy), make_pair(k, 0)));
	check[sx][sy][k] = true;
	int nx = 0;
	int ny = 0;

	while (!q.empty()) {
		int hx = q.front().first.first;
		int hy = q.front().first.second;
		int hk = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (hx == h - 1 && hy == w - 1 && box[hx][hy]!=1) {
			cout << cnt;
			return;
		}

		if (hk != 0) {
			for (int i = 0; i < 8; i++) {
				nx = hx + ddx[i];
				ny = hy + ddy[i];

				if (nx >= 0 && ny >= 0 && nx < h && ny < w && check[nx][ny][hk-1] == false && box[nx][ny] != 1) {
					check[nx][ny][hk-1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(hk-1, cnt + 1)));
				}
			}
		}
		
		for (int i = 0; i < 4; i++) {
			nx = hx + dx[i];
			ny = hy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < h && ny < w && check[nx][ny][hk] == false && box[nx][ny] != 1) {
				check[nx][ny][hk] = true;
				q.push(make_pair(make_pair(nx, ny), make_pair(hk, cnt + 1)));
			}
		}

	}
	cout << -1;
	return;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> box[i][j];
	
	bfs(0, 0);

}
/*
	백준 1600번 말이 되고픈 원숭이
*/
