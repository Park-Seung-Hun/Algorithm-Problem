#include <iostream>
#include <queue>
using namespace std;

char box[50][50];
bool check[50][50];

int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };

queue<pair<int, int> > water;
int n, m;

void bfs(int x,int y) {
	int cnt = 0;
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(cnt, make_pair(x, y)));
	queue<pair<int, int> > copy;
	queue<pair<int, pair<int, int> > > copy2;

	while (!q.empty()) {
		
		while (!water.empty()) {
			int wx = water.front().first;
			int wy = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nwx = wx + xx[i];
				int nwy = wy + yy[i];

				if (nwx >= 0 && nwx < n && nwy >= 0 && nwy < m && box[nwx][nwy] == '.') {
					box[nwx][nwy] = '*';
					copy.push(make_pair(nwx, nwy));
				}
			}
		} 
		while (!copy.empty()) {
			int xc = copy.front().first;
			int yc = copy.front().second;
			copy.pop();

			water.push(make_pair(xc, yc));
		}
		// 물퍼지기

		while (!q.empty()) {
			int cx = q.front().second.first;
			int cy = q.front().second.second;
			int ans = q.front().first;
			q.pop();
			if (box[cx][cy] == 'D') {
				cout << ans;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + xx[i];
				int ny = cy + yy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && check[nx][ny] == false) {
					if (box[nx][ny] == '.' || box[nx][ny] == 'D') {
						check[nx][ny] = true;
						copy2.push(make_pair(ans + 1, make_pair(nx, ny)));
					}
				}
			}
		}		
		while (!copy2.empty()) {
			int xc2 = copy2.front().second.first;
			int yc2 = copy2.front().second.second;
			int cnt = copy2.front().first;

			copy2.pop();

			q.push(make_pair(cnt,make_pair(xc2,yc2)));
		}
	}

	cout << "KAKTUS";
	return;
}

int main() {
	int row = 0;
	int col = 0;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			box[i][j] = a[j];
			if (box[i][j] == 'S') {
				row = i;
				col = j;
			}
			else if (box[i][j] == '*') {
				water.push(make_pair(i, j));
			}
		}
	}
	
	bfs(row,col);

}
/*
	백준 3055번 탈출
*/
