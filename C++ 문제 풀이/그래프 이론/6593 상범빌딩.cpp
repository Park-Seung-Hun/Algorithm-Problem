
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char building[30][30][30];
bool check[30][30][30];
int l, r, c, ans;
int sl, sr, sc;

typedef struct node {
	int x;
	int y;
	int z;
	int cnt;
};

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

void bfs(int x, int y, int z) {
	queue<node> q;
	q.push({ x,y,z,0 });
	check[x][y][z]=true;

	while (!q.empty()) {
		int hx = q.front().x;
		int hy = q.front().y;
		int hz = q.front().z;
		int hcnt = q.front().cnt;
		q.pop();

		if (building[hx][hy][hz] == 'E') {
			ans = hcnt;
			return;
		}

		for (int i = 0; i < 6; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			int nz = hz + dz[i];

			if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
			if (check[nx][ny][nz]) continue;
			if (building[nx][ny][nz] == '.' || building[nx][ny][nz] == 'E') {
				check[nx][ny][nz] = true;
				q.push({ nx,ny,nz,hcnt + 1 });
			}

		}
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> l >> r >> c;
		ans = 0;


		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						sl = i, sr = j, sc = k;
					}
					check[i][j][k] = false;
				}
			}
		}

		bfs(sl, sr, sc);

		if (!ans) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}

	return 0;
}
