#include <iostream>
#include <queue>
using namespace std;

int  m, n, h;
bool complete, flag;
int tomato[100][100][100];
int ans[100][100][100] = { -1, };
bool check[100][100][100];
int movex[6] = { 0,0,-1,1,0,0 };
int movey[6] = { -1,1,0,0,0,0 };
int movez[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, pair<int,int>>>q;

void bfs(int x,int y,int z) {
	
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[j][k][i];
				if (tomato[j][k][i]) complete = true;

				if (tomato[j][k][i] == 1) {
					check[j][k][i] = true;
					ans[j][k][i] = 0;
					q.push(make_pair(make_pair(j, k), make_pair(i, 0)));
				}
			}
		}
	}

	while (!q.empty()) {
		int hx = q.front().first.first;
		int hy = q.front().first.second;
		int hz = q.front().second.first;
		int cost = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];
			int nz = hz + movez[i];

			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h) {
				if (check[nx][ny][nz] == false && tomato[nx][ny][nz] == 0) {
					check[nx][ny][nz] = true;
					tomato[nx][ny][nz] = 1;
					ans[nx][ny][nz] = cost + 1;
					q.push(make_pair(make_pair(nx, ny), make_pair(nz,cost+1)));
				}
			}
		}
	}

	int Ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[j][k][i] == 0) flag = true;
				if (Ans < ans[j][k][i]) Ans = ans[j][k][i];
			}
			if (flag) break;
		}
		if (flag) break;
	}

	if (complete) {
		if (flag) cout << -1 << '\n';
		else cout << Ans << '\n';
	}
	else cout << 0 << '\n';
}
/*
	백준 7569번 토마토
*/
