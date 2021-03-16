#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[50001];
int depth[50001];
bool visited[50001];
vector<int> edge[50001];
queue<int> q;

// LCA 구하기
int LCA(int u, int v) {

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

	// 1. edge 입력
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	// 2. BFS를 이용홰 노드의 깊이 구하기
	visited[1] = true;
	q.push(1);
	depth[1] = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < edge[here].size(); i++) {
			int next = edge[here][i];

			if (visited[next]) continue;
			visited[next] = true;
			depth[next] = depth[here] + 1;
			parent[next] = here;
			q.push(next);
		}
	}


	//3. LCA
	cin >> m;
	for (int i = 0; i < m; i++) {
		int z,w;
		cin >> z >> w;
		cout << LCA(z, w) << '\n';
	}

	return 0;
}
