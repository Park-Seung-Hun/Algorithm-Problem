#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int sheep, wolf;
int X[4] = { 0,0,1,-1 };
int Y[4] = { 1,-1,0,0 };

void sol(int x, int y, vector<vector<bool> >& check, vector<vector<char> >& box) {
	check[x][y] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	int w = 0; int s = 0;

	while (!q.empty()) {
		int hx = q.front().first; int hy = q.front().second;
		if (box[hx][hy] == 'v') w++;
		if (box[hx][hy] == 'o') s++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + X[i]; int ny = hy + Y[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (check[nx][ny] == false && box[nx][ny] != '#') {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
	if (w >= s) sheep -= s;
	else wolf -= w;

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<char> > box(n, vector<char>(m, 0));
	vector<vector<bool> > check(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < t.size(); j++) {
			box[i][j] = t[j];
			if (t[j] == 'o') sheep++;
			if (t[j] == 'v') wolf++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == false && box[i][j] != '#') {
				sol(i, j, check, box);
			}
		}
	}
	cout << sheep << ' ' << wolf;
}

/*
	백준 3184번 양
*/

