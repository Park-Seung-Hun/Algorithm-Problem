/*
LCA란? 최소 공통 조상을 찾는 방법
O(logN)의 방법으로 LCA 사용 최소 공통 조상
O(N)의 방법으론?
*/

#include <iostream>
#include <vector>
using namespace std;
int parent[1024][11];
int depth[1024];

void dfs(int n,int d) {
	depth[n] = d;
	parent[n][0] = n / 2;

	int next = n * 2;
	if (next >= 1024) return;

	dfs(next, d + 1);
	dfs(next + 1, d + 1);
}
int lca(int x, int y) {
	if (depth[x] > depth[y]) {
		int tmp = x;
		x = y;
		y = tmp;
	}

	for (int i = 10; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}

	if (x == y)
		return x;

	for (int i = 10; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}

	return parent[x][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 연결해준 노드의 부모 노드를 찾는다.
	dfs(1, 1);
	for (int j = 1; j < 11; j++) {
		for (int i = 1; i <= 1023; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}

	int t, A, B;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> A >> B;
		cout << lca(A, B)*10 << '\n';
	}
	return 0;
}


/*
LCA O(N)의 방법도 가능하다.
해당 방법은 depth를 맞춰 준 다음 공통 조상을 찾는 방법이다.
*/

#include <iostream>
#include <vector>
using namespace std;
int parent[1024];
int depth[1024];

void dfs(int n,int d) {
	depth[n] = d;
	parent[n] = n / 2;

	int next = n * 2;
	if (next >= 1024) return;

	dfs(next, d + 1);
	dfs(next + 1, d + 1);
}
int lca(int u, int v) {

	// depth를 맞춰주기 위해 부모노드를 타고 올라온다.
	if (depth[u] < depth[v]) while (depth[u] != depth[v]) v = parent[v];
	else while (depth[u] != depth[v]) u = parent[u];

	// 공통 조상 노드를 찾기 위해 부모노드로 올라온다.
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}

	return v;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 연결해준 노드의 부모 노드를 찾는다.
	dfs(1, 1);

	int t, A, B;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> A >> B;
		cout << lca(A, B)*10 << '\n';
	}
	return 0;
}
