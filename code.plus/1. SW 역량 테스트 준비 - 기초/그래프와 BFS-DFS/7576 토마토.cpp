#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int> > box;
vector<vector<bool> > check;
vector<vector<int> > ans;
queue<pair<pair<int, int>, int> > q;

int movex[4] = { 0,0,-1,1 };
int movey[4] = { 1,-1,0,0 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	box.assign(n, vector<int>(m, 0));
	check.assign(n, vector<bool>(m, false));
	ans.assign(n, vector<int>(m, -1));

	bool complete = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if(box[i][j]==0) complete = true;

			if (box[i][j] == 1) {

				check[i][j] = true;
				ans[i][j] = 0;
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	while (!q.empty()) {
		int hx = q.front().first.first;
		int hy = q.front().first.second;
		int cost = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (check[nx][ny] == false && box[nx][ny] == 0) {
					box[nx][ny] = 1;
					ans[nx][ny] = cost + 1;
					check[nx][ny] = true;

					q.push(make_pair(make_pair(nx, ny), cost + 1));
				}
			}
		}

	}

	int Ans = 0;
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) flag = true;
			if (Ans < ans[i][j]) Ans = ans[i][j];
		}
		if (flag) break;
	}


	if (complete == false) cout << 0 << '\n';
	else {
		if (flag) cout << -1 << '\n';
		else cout << Ans << '\n';
	}
}
/*
	백준 7576번 토마토
*/
