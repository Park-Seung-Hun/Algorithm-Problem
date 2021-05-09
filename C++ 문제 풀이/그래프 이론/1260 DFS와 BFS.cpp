#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;

int edge[1001][1001];
bool D[1001];
bool B[1001];

void dfs(int idx) {
	D[idx] = true;
	cout << idx << ' ';

	for (int i = 1; i <=n; i++) {
		
		if (D[i] == false&&edge[idx][i]==1) {
			dfs(i);
		}
	}
	return;
}

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	B[idx] = true;

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		cout << here << ' ';

		for (int i = 1; i <= n;i++) {
			
			if (B[i] == false && edge[here][i]==1) {
				q.push(i);
				B[i] = true;
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		edge[x][y] = 1;
		edge[y][x] = 1;
	}
	dfs(v);
	cout << '\n';
	bfs(v);

}
/*
	백준 1260번 DFS와 BFS
*/
