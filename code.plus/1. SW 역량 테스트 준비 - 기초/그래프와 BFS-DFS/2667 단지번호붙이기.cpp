#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,tot;
int home[25][25];
int check[25][25];
vector<int> cnt;

int movex[4] = { 0,0,-1,1 };
int movey[4] = { 1,-1,0,0 };

void bfs(int x,int y) {
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	check[x][y] = true;
	
	int count = 1;

	while (!q.empty()) {
		int hx = q.front().first; 
		int hy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = hx + movex[i];
			int ny = hy + movey[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (check[nx][ny] == false && home[nx][ny] == 1) {
					count++;
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	tot++;
	cnt.push_back(count);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;

		for (int j = 0; j < t.size(); j++) {
			int x = t[j] - '0';
			home[i][j] = x;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false && home[i][j] == 1) {
				bfs(i, j);
			}
		}
	}
	
	sort(cnt.begin(), cnt.end());
	cout << tot << '\n';
	for (int i = 0; i < cnt.size(); i++) cout << cnt[i] << '\n';
}
/*
	백준 2667번 단지번호붙이기
*/
